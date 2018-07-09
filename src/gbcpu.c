

#include "gbcpu.h"

#include <stdio.h>
#include <cpuinst.h>
#include <assert.h>

#include "gbreg.h"
#include "gbmem.h"
#include "bootrom.h"
#include "cputable.h"
#include "gbcart.h"
#include "cpuop.h"

const int TMC_BIT_TO_TIMER_COUNT[] = {1024, 16, 64, 256};
const u8 IRQ_TO_SERVICE_ADDR[] = {0x40, 0x48, 0x50, 0x00, 0x60, 0x00, 0x00, 0x00};

int divTimerTick = DIVIDER_CYCLES;               // current divider timer tick
int timerTick = 1024;                  // current timer tick
int scanlineTick = SCANLINE_CYCLES;
bool interruptsEnabled = false;     // interrupt master enable flag set by EI/DI

void gb_init() {
    gb_reset();
}

void gb_reset() {
    gb_meminit();
}

void gb_load(u8 *rom, size_t sz) {

}

void gb_update(int cycles) {
    int count = 0;

    while (count < cycles) {
        cpuinst *inst = gb_step();
        count += inst->cycles;
        gb_update_timer(inst->cycles);
        gb_update_gfx(inst->cycles);
        gb_do_interrupt();
    }
}

void gb_inst_run(u8 opcode, cpuinst *inst) {
    if (inst->impl) {
        switch (inst->len) {
            case 0: {
                printf("0x%02x\t%s\t%s\n", opcode, inst->disasm, inst->desc);
                ((void (*)(void)) (inst->impl))();

                break;
            }
            case 1: {
                u8 op = gb_read8(reg.pc++);
                printf("0x%02x\t0x%02x\t%s\t%s\n", opcode, op, inst->disasm, inst->desc);
                ((void (*)(u8)) (inst->impl))(op);

                break;
            }
            case 2: {
                u16 op = gb_read16(reg.pc);
                reg.pc += 2;
                printf("0x%02x\t0x%04x\t%s\t%s\n", opcode, op, inst->disasm, inst->desc);
                ((void (*)(u16)) (inst->impl))(op);
                break;
            }
            default:
                assert(0);
                break;
        }
    } else {
        printf("unimplemented opcode 0x%02x\n", opcode);
        assert(0);
    }
}

cpuinst *gb_step() {
    u8 opcode = gb_read8(reg.pc++);
    cpuinst *inst = gb_inst_table + opcode;
    gb_inst_run(opcode, inst);
    return inst;
}

void gb_printreg() {
    printf("PC: %04x\tSP: %04x\n"
                   "A: %02x\tB: %02x\tC: %02x\tD: %02x\tE: %02x\tF: %02x\tH: %02x\tL: %02x\n",
           reg.pc, reg.sp, reg.a, reg.b, reg.c, reg.d, reg.e, reg.f, reg.h, reg.l);
}

void gb_update_timer(int cycles) {
    // divider register update
    divTimerTick -= cycles;
    if (divTimerTick <= 0) {
        divTimerTick += DIVIDER_CYCLES;    // assumption: no inst >256 cycles
        mem.raw[DIV_REG]++;
    }

    if (gb_read8(TMC) & (1 << 2)) {   // clock enabled testbit
        timerTick -= cycles;
        if (timerTick <= 0) {
            // assumption: change TMC does not cause reset, and
            // no instruction has more cycles than min timer count
            timerTick += TMC_BIT_TO_TIMER_COUNT[gb_read8(TMC) & 0x3];
            if (gb_read8(TIMA) >= 255) {
                gb_write8(TIMA, gb_read8(TMA));
                gb_req_interrupt(IRQ_TIMER);
            } else {
                gb_write8(TIMA, (u8) (gb_read8(TIMA) + 1));
            }
        }
    }
}

void gb_update_gfx(int cycles) {
    // lcd status manipulation
    u8 sta = gb_read8(LCD_STA);
    if (gb_read8(LCD_CTL) & (1 << 7)) {   // lcd enabled
        u8 currentLine = gb_read8(SCAN_LN);
        u8 currentMode = (u8) (sta & 0x3);
        u8 mode = 0;
        bool reqInt = false;

        if (currentLine >= 144) {
            mode = 1;
            sta = (u8) ((sta | 1) & ~(1 << 1));
            reqInt = (bool) (sta & (1 << 4));
        } else {
            if (scanlineTick >= LCD_MODE2_BOUNDS) {
                mode = 2;
                sta = (u8) ((sta | 2) & ~1);
                reqInt = (bool) (sta & (1 << 5));
            } else if (scanlineTick >= LCD_MODE3_BOUNDS) {
                mode = 3;
                sta |= 3;
            } else {
                mode = 0;
                sta &= ~3;
                reqInt = (bool) (sta & (1 << 3));
            }
        }

        if (reqInt && (mode != currentMode))
            gb_req_interrupt(IRQ_LCD);

        if (currentLine == gb_read8(0xff45)) {
            sta |= 1 << 2;
            if (sta & (1 << 6))
                gb_req_interrupt(IRQ_LCD);
        } else {
            sta &= ~(1 << 2);
        }
        gb_write8(LCD_STA, sta);

        // gfx manipulation
        scanlineTick -= cycles;
        if(scanlineTick <= 0){
            scanlineTick += SCANLINE_CYCLES;
            mem.raw[SCAN_LN]++;
            currentLine = gb_read8(SCAN_LN);

            if(currentLine == 144)
                gb_req_interrupt(IRQ_VBLANK);
            else if(currentLine > 153)
                mem.raw[SCAN_LN] = 0;
            else if(currentLine < 144){
                // TODO draw
            }
        }
    } else {
        scanlineTick = SCANLINE_CYCLES;
        mem.raw[SCAN_LN] = 0;
        gb_write8(LCD_STA, (u8) ((sta & 252) | 1));
    }
}

void gb_do_interrupt() {
    if (interruptsEnabled) {
        u8 req = gb_read8(IRQ_REG);
        u8 en = gb_read8(IRQ_EN);
        if (req > 0) {
            for (int i = 0; i < 8; i++) {
                if ((req & (1 << i)) && (en & (1 << i))) {
                    interruptsEnabled = false;
                    gb_write8(IRQ_REG, (u8) (gb_read8(IRQ_REG) & ~(1 << i)));   // reset irq bit
                    a_push_reg(reg.pc);
                    reg.pc = IRQ_TO_SERVICE_ADDR[i];
                    assert(reg.pc > 0);
                    return;
                }
            }
        }
    }
}

void gb_req_interrupt(u8 irq) {
    gb_write8(IRQ_REG, gb_read8(IRQ_REG) | irq);
}






