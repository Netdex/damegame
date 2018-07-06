

#include "gbcpu.h"

#include <stdio.h>
#include <cpuinst.h>
#include <assert.h>

#include "gbreg.h"
#include "gbmem.h"
#include "bootrom.h"
#include "cputable.h"
#include "gbcart.h"




void gb_init() {
    gb_reset();
}

void gb_reset() {
    gb_meminit();
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




