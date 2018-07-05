

#include "gbcpu.h"

#include <stdio.h>
#include <cpuinst.h>
#include <assert.h>

#include "gbreg.h"
#include "gbmem.h"
#include "bootrom.h"
#include "cputable.h"

bool gb_do_interrupt = false;   // TODO determine initial state

void gb_init() {
    gb_write(0, bootrom, 256);
    gb_reset();
}

void gb_reset() {
    reg.pc = 0x100;
    reg.af = 0x01b0;    reg.bc = 0x0013;    reg.de = 0x00d8;    reg.hl = 0x014d;
    reg.sp = 0xfffe;
    gb_memset(0xff05, 0, 0x3);
    gb_write8(0xff05, 0x00);    gb_write8(0xff06, 0x00);    gb_write8(0xff07, 0x00);
    gb_write8(0xff10, 0x80);    gb_write8(0xff11, 0xbf);    gb_write8(0xff12, 0xf3);
    gb_write8(0xff14, 0xbf);    gb_write8(0xff16, 0x3f);    gb_write8(0xff17, 0x00);
    gb_write8(0xff19, 0xbf);    gb_write8(0xff1a, 0x7f);    gb_write8(0xff1b, 0xff);
    gb_write8(0xff1c, 0x9f);    gb_write8(0xff1e, 0xbf);    gb_write8(0xff20, 0xff);
    gb_write8(0xff21, 0x00);    gb_write8(0xff22, 0x00);    gb_write8(0xff23, 0xbf);
    gb_write8(0xff24, 0x77);    gb_write8(0xff25, 0xf3);    gb_write8(0xff26, 0xf1);
    gb_write8(0xff40, 0x91);    gb_write8(0xff42, 0x00);    gb_write8(0xff43, 0x00);
    gb_write8(0xff45, 0x00);    gb_write8(0xff47, 0xfc);    gb_write8(0xff48, 0xff);
    gb_write8(0xff49, 0xff);    gb_write8(0xff4a, 0x00);    gb_write8(0xff4b, 0x00);
    gb_write8(0xffff, 0x00);
}

void gb_load(u8 *rom, size_t sz) {

}

void gb_inst_run(u8 opcode, cpuinst *inst){
    if(inst->impl) {
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
    }
    else{
        printf("unimplemented opcode 0x%02x\n", opcode);
        assert(0);
    }
}

cpuinst* gb_step() {
    u8 opcode = gb_read8(reg.pc++);
    cpuinst *inst = gb_inst_table + opcode;
    gb_inst_run(opcode, inst);
    return inst;
}

void gb_printreg(){
    printf("PC: %04x\tSP: %04x\n"
           "A: %02x\tB: %02x\tC: %02x\tD: %02x\tE: %02x\tF: %02x\tH: %02x\tL: %02x\n",
            reg.pc, reg.sp, reg.a, reg.b, reg.c, reg.d, reg.e, reg.f, reg.h, reg.l);
}

void gb_update_timer() {

}




