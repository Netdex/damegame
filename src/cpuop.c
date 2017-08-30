

#include "cpuop.h"


/* 3.3.1. 8-Bit Loads */
// 1. LD nn,n
/* 0x06 */	void op_ld_reg_b_imm_n(uint8_t *op){
	reg.b = *op;
}
/* 0x0E */	void op_ld_reg_c_imm_n(uint8_t *op){
	reg.c = *op;
}
/* 0x16 */	void op_ld_reg_d_imm_n(uint8_t *op){
	reg.d = *op;
}
/* 0x1E */	void op_ld_reg_e_imm_n(uint8_t *op){
	reg.e = *op;
}
/* 0x26 */	void op_ld_reg_h_imm_n(uint8_t *op){
	reg.h = *op;
}
/* 0x2E */	void op_ld_reg_l_imm_n(uint8_t *op){
	reg.l = *op;
}

// 2. LD r1,r2
/* 0x7F */	void op_ld_reg_a_reg_a(uint8_t *op){
    reg.a = reg.a;
}
/* 0x78 */	void op_ld_reg_a_reg_b(uint8_t *op){
    reg.a = reg.b;
}
/* 0x79 */	void op_ld_reg_a_reg_c(uint8_t *op){
    reg.a = reg.c;
}
/* 0x7A */	void op_ld_reg_a_reg_d(uint8_t *op){
    reg.a = reg.d;
}
/* 0x7B */	void op_ld_reg_a_reg_e(uint8_t *op){
    reg.a = reg.e;
}
/* 0x7C */	void op_ld_reg_a_reg_h(uint8_t *op){
    reg.a = reg.h;
}
/* 0x7D */	void op_ld_reg_a_reg_l(uint8_t *op){
    reg.a = reg.l;
}
/* 0x7E */	void op_ld_reg_a_ind_hl(uint8_t *op){
    reg.a = gb_read8(reg.hl);
}
/* 0x40 */	void op_ld_reg_b_reg_b(uint8_t *op){
    reg.b = reg.b;
}
/* 0x41 */	void op_ld_reg_b_reg_c(uint8_t *op){
    reg.b = reg.c;
}
/* 0x42 */	void op_ld_reg_b_reg_d(uint8_t *op){
    reg.b = reg.d;
}
/* 0x43 */	void op_ld_reg_b_reg_e(uint8_t *op){
    reg.b = reg.e;
}
/* 0x44 */	void op_ld_reg_b_reg_h(uint8_t *op){
    reg.b = reg.h;
}
/* 0x45 */	void op_ld_reg_b_reg_l(uint8_t *op){
    reg.b = reg.l;
}
/* 0x46 */	void op_ld_reg_b_ind_hl(uint8_t *op){
    reg.b = gb_read8(reg.hl);
}
/* 0x48 */	void op_ld_reg_c_reg_b(uint8_t *op){
    reg.c = reg.b;
}
/* 0x49 */	void op_ld_reg_c_reg_c(uint8_t *op){
    reg.c = reg.c;
}
/* 0x4A */	void op_ld_reg_c_reg_d(uint8_t *op){
    reg.c = reg.d;
}
/* 0x4B */	void op_ld_reg_c_reg_e(uint8_t *op){
    reg.c = reg.e;
}
/* 0x4C */	void op_ld_reg_c_reg_h(uint8_t *op){
    reg.c = reg.h;
}
/* 0x4D */	void op_ld_reg_c_reg_l(uint8_t *op){
    reg.c = reg.l;
}
/* 0x4E */	void op_ld_reg_c_ind_hl(uint8_t *op){
    reg.c = gb_read8(reg.hl);
}
/* 0x50 */	void op_ld_reg_d_reg_b(uint8_t *op){
    reg.d = reg.b;
}
/* 0x51 */	void op_ld_reg_d_reg_c(uint8_t *op){
    reg.d = reg.c;
}
/* 0x52 */	void op_ld_reg_d_reg_d(uint8_t *op){
    reg.d = reg.d;
}
/* 0x53 */	void op_ld_reg_d_reg_e(uint8_t *op){
    reg.d = reg.e;
}
/* 0x54 */	void op_ld_reg_d_reg_h(uint8_t *op){
    reg.d = reg.h;
}
/* 0x55 */	void op_ld_reg_d_reg_l(uint8_t *op){
    reg.d = reg.l;
}
/* 0x56 */	void op_ld_reg_d_ind_hl(uint8_t *op){
    reg.d = gb_read8(reg.hl);
}
/* 0x58 */	void op_ld_reg_e_reg_b(uint8_t *op){
    reg.e = reg.b;
}
/* 0x59 */	void op_ld_reg_e_reg_c(uint8_t *op){
    reg.e = reg.c;
}
/* 0x5A */	void op_ld_reg_e_reg_d(uint8_t *op){
    reg.e = reg.d;
}
/* 0x5B */	void op_ld_reg_e_reg_e(uint8_t *op){
    reg.e = reg.e;
}
/* 0x5C */	void op_ld_reg_e_reg_h(uint8_t *op){
    reg.e = reg.h;
}
/* 0x5D */	void op_ld_reg_e_reg_l(uint8_t *op){
    reg.e = reg.l;
}
/* 0x5E */	void op_ld_reg_e_ind_hl(uint8_t *op){
    reg.e = gb_read8(reg.hl);
}
/* 0x60 */	void op_ld_reg_h_reg_b(uint8_t *op){
    reg.h = reg.b;
}
/* 0x61 */	void op_ld_reg_h_reg_c(uint8_t *op){
    reg.h = reg.c;
}
/* 0x62 */	void op_ld_reg_h_reg_d(uint8_t *op){
    reg.h = reg.d;
}
/* 0x63 */	void op_ld_reg_h_reg_e(uint8_t *op){
    reg.h = reg.e;
}
/* 0x64 */	void op_ld_reg_h_reg_h(uint8_t *op){
    reg.h = reg.h;
}
/* 0x65 */	void op_ld_reg_h_reg_l(uint8_t *op){
    reg.h = reg.l;
}
/* 0x66 */	void op_ld_reg_h_ind_hl(uint8_t *op){
    reg.h = gb_read8(reg.hl);
}
/* 0x68 */	void op_ld_reg_l_reg_b(uint8_t *op){
    reg.l = reg.b;
}
/* 0x69 */	void op_ld_reg_l_reg_c(uint8_t *op){
    reg.l = reg.c;
}
/* 0x6A */	void op_ld_reg_l_reg_d(uint8_t *op){
    reg.l = reg.d;
}
/* 0x6B */	void op_ld_reg_l_reg_e(uint8_t *op){
    reg.l = reg.e;
}
/* 0x6C */	void op_ld_reg_l_reg_h(uint8_t *op){
    reg.l = reg.h;
}
/* 0x6D */	void op_ld_reg_l_reg_l(uint8_t *op){
    reg.l = reg.l;
}
/* 0x6E */	void op_ld_reg_l_ind_hl(uint8_t *op){
    reg.l = gb_read8(reg.hl);
}
/* 0x70 */	void op_ld_ind_hl_reg_b(uint8_t *op){
    gb_write8(reg.hl, reg.b);
}
/* 0x71 */	void op_ld_ind_hl_reg_c(uint8_t *op){
    gb_write8(reg.hl, reg.c);
}
/* 0x72 */	void op_ld_ind_hl_reg_d(uint8_t *op){
    gb_write8(reg.hl, reg.d);
}
/* 0x73 */	void op_ld_ind_hl_reg_e(uint8_t *op){
    gb_write8(reg.hl, reg.e);
}
/* 0x74 */	void op_ld_ind_hl_reg_h(uint8_t *op){
    gb_write8(reg.hl, reg.h);
}
/* 0x75 */	void op_ld_ind_hl_reg_l(uint8_t *op){
    gb_write8(reg.hl, reg.l);
}
/* 0x36 */	void op_ld_ind_hl_imm_n(uint8_t *op){
    gb_write8(reg.hl, *op);
}

// 3. LD A,n (ignore duplicates)
/* 0x0A */  void op_ld_reg_a_ind_bc(uint8_t *op){
    reg.a = gb_read8(reg.bc);
}
/* 0x1A */  void op_ld_reg_a_ind_de(uint8_t *op){
    reg.a = gb_read8(reg.de);
}
/* 0xFA */  void op_ld_reg_a_ind_nn(uint8_t *op){
    reg.a = gb_read8((op[0] << 8) | op[1]);
}
/* 0x3E */  void op_ld_reg_a_imm_n(uint8_t *op){
    reg.a = *op;
}

// 4. LD n,A
/* 0x47 */  void op_ld_reg_b_reg_a(uint8_t *op){
    reg.b = reg.a;
}
/* 0x4F */  void op_ld_reg_c_reg_a(uint8_t *op){
    reg.c = reg.a;
}
/* 0x57 */  void op_ld_reg_d_reg_a(uint8_t *op){
    reg.d = reg.a;
}
/* 0x5F */  void op_ld_reg_e_reg_a(uint8_t *op){
    reg.e = reg.a;
}
/* 0x67 */  void op_ld_reg_h_reg_a(uint8_t *op){
    reg.h = reg.a;
}
/* 0x6F */  void op_ld_reg_l_reg_a(uint8_t *op){
    reg.l = reg.a;
}
/* 0x02 */  void op_ld_ind_bc_reg_a(uint8_t *op){
    gb_write8(reg.bc, reg.a);
}
/* 0x12 */  void op_ld_ind_de_reg_a(uint8_t *op){
    gb_write8(reg.de, reg.a);
}
/* 0x77 */  void op_ld_ind_hl_reg_a(uint8_t *op){
    gb_write8(reg.hl, reg.a);
}
/* 0xEA */  void op_ld_ind_nn_reg_a(uint8_t *op){
    gb_write8((op[0] << 8) | op[1], reg.a);
}



/* 0x00 */	void op_nop(uint8_t *op){

}