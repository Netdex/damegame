

#include <gbreg.h>
#include "cpuop.h"


/* 3.3.1. 8-Bit Loads */
// 1. LD nn,n
/* 06 */	void op_ld_reg_b_imm_n(u8 *op){
	reg.b = *op;
}
/* 0E */	void op_ld_reg_c_imm_n(u8 *op){
	reg.c = *op;
}
/* 16 */	void op_ld_reg_d_imm_n(u8 *op){
	reg.d = *op;
}
/* 1E */	void op_ld_reg_e_imm_n(u8 *op){
	reg.e = *op;
}
/* 26 */	void op_ld_reg_h_imm_n(u8 *op){
	reg.h = *op;
}
/* 2E */	void op_ld_reg_l_imm_n(u8 *op){
	reg.l = *op;
}

// 2. LD r1,r2
/* 7F */	void op_ld_reg_a_reg_a(u8 *op){
    reg.a = reg.a;
}
/* 78 */	void op_ld_reg_a_reg_b(u8 *op){
    reg.a = reg.b;
}
/* 79 */	void op_ld_reg_a_reg_c(u8 *op){
    reg.a = reg.c;
}
/* 7A */	void op_ld_reg_a_reg_d(u8 *op){
    reg.a = reg.d;
}
/* 7B */	void op_ld_reg_a_reg_e(u8 *op){
    reg.a = reg.e;
}
/* 7C */	void op_ld_reg_a_reg_h(u8 *op){
    reg.a = reg.h;
}
/* 7D */	void op_ld_reg_a_reg_l(u8 *op){
    reg.a = reg.l;
}
/* 7E */	void op_ld_reg_a_ind_hl(u8 *op){
    reg.a = gb_read8(reg.hl);
}
/* 40 */	void op_ld_reg_b_reg_b(u8 *op){
    reg.b = reg.b;
}
/* 41 */	void op_ld_reg_b_reg_c(u8 *op){
    reg.b = reg.c;
}
/* 42 */	void op_ld_reg_b_reg_d(u8 *op){
    reg.b = reg.d;
}
/* 43 */	void op_ld_reg_b_reg_e(u8 *op){
    reg.b = reg.e;
}
/* 44 */	void op_ld_reg_b_reg_h(u8 *op){
    reg.b = reg.h;
}
/* 45 */	void op_ld_reg_b_reg_l(u8 *op){
    reg.b = reg.l;
}
/* 46 */	void op_ld_reg_b_ind_hl(u8 *op){
    reg.b = gb_read8(reg.hl);
}
/* 48 */	void op_ld_reg_c_reg_b(u8 *op){
    reg.c = reg.b;
}
/* 49 */	void op_ld_reg_c_reg_c(u8 *op){
    reg.c = reg.c;
}
/* 4A */	void op_ld_reg_c_reg_d(u8 *op){
    reg.c = reg.d;
}
/* 4B */	void op_ld_reg_c_reg_e(u8 *op){
    reg.c = reg.e;
}
/* 4C */	void op_ld_reg_c_reg_h(u8 *op){
    reg.c = reg.h;
}
/* 4D */	void op_ld_reg_c_reg_l(u8 *op){
    reg.c = reg.l;
}
/* 4E */	void op_ld_reg_c_ind_hl(u8 *op){
    reg.c = gb_read8(reg.hl);
}
/* 50 */	void op_ld_reg_d_reg_b(u8 *op){
    reg.d = reg.b;
}
/* 51 */	void op_ld_reg_d_reg_c(u8 *op){
    reg.d = reg.c;
}
/* 52 */	void op_ld_reg_d_reg_d(u8 *op){
    reg.d = reg.d;
}
/* 53 */	void op_ld_reg_d_reg_e(u8 *op){
    reg.d = reg.e;
}
/* 54 */	void op_ld_reg_d_reg_h(u8 *op){
    reg.d = reg.h;
}
/* 55 */	void op_ld_reg_d_reg_l(u8 *op){
    reg.d = reg.l;
}
/* 56 */	void op_ld_reg_d_ind_hl(u8 *op){
    reg.d = gb_read8(reg.hl);
}
/* 58 */	void op_ld_reg_e_reg_b(u8 *op){
    reg.e = reg.b;
}
/* 59 */	void op_ld_reg_e_reg_c(u8 *op){
    reg.e = reg.c;
}
/* 5A */	void op_ld_reg_e_reg_d(u8 *op){
    reg.e = reg.d;
}
/* 5B */	void op_ld_reg_e_reg_e(u8 *op){
    reg.e = reg.e;
}
/* 5C */	void op_ld_reg_e_reg_h(u8 *op){
    reg.e = reg.h;
}
/* 5D */	void op_ld_reg_e_reg_l(u8 *op){
    reg.e = reg.l;
}
/* 5E */	void op_ld_reg_e_ind_hl(u8 *op){
    reg.e = gb_read8(reg.hl);
}
/* 60 */	void op_ld_reg_h_reg_b(u8 *op){
    reg.h = reg.b;
}
/* 61 */	void op_ld_reg_h_reg_c(u8 *op){
    reg.h = reg.c;
}
/* 62 */	void op_ld_reg_h_reg_d(u8 *op){
    reg.h = reg.d;
}
/* 63 */	void op_ld_reg_h_reg_e(u8 *op){
    reg.h = reg.e;
}
/* 64 */	void op_ld_reg_h_reg_h(u8 *op){
    reg.h = reg.h;
}
/* 65 */	void op_ld_reg_h_reg_l(u8 *op){
    reg.h = reg.l;
}
/* 66 */	void op_ld_reg_h_ind_hl(u8 *op){
    reg.h = gb_read8(reg.hl);
}
/* 68 */	void op_ld_reg_l_reg_b(u8 *op){
    reg.l = reg.b;
}
/* 69 */	void op_ld_reg_l_reg_c(u8 *op){
    reg.l = reg.c;
}
/* 6A */	void op_ld_reg_l_reg_d(u8 *op){
    reg.l = reg.d;
}
/* 6B */	void op_ld_reg_l_reg_e(u8 *op){
    reg.l = reg.e;
}
/* 6C */	void op_ld_reg_l_reg_h(u8 *op){
    reg.l = reg.h;
}
/* 6D */	void op_ld_reg_l_reg_l(u8 *op){
    reg.l = reg.l;
}
/* 6E */	void op_ld_reg_l_ind_hl(u8 *op){
    reg.l = gb_read8(reg.hl);
}
/* 70 */	void op_ld_ind_hl_reg_b(u8 *op){
    gb_write8(reg.hl, reg.b);
}
/* 71 */	void op_ld_ind_hl_reg_c(u8 *op){
    gb_write8(reg.hl, reg.c);
}
/* 72 */	void op_ld_ind_hl_reg_d(u8 *op){
    gb_write8(reg.hl, reg.d);
}
/* 73 */	void op_ld_ind_hl_reg_e(u8 *op){
    gb_write8(reg.hl, reg.e);
}
/* 74 */	void op_ld_ind_hl_reg_h(u8 *op){
    gb_write8(reg.hl, reg.h);
}
/* 75 */	void op_ld_ind_hl_reg_l(u8 *op){
    gb_write8(reg.hl, reg.l);
}
/* 36 */    void op_ld_ind_hl_imm_n(u8 *op){
    gb_write8(reg.hl, *op);
}

// 3. LD A,n (ignore duplicates)
/* 0A */    void op_ld_reg_a_ind_bc(u8 *op){
    reg.a = gb_read8(reg.bc);
}
/* 1A */    void op_ld_reg_a_ind_de(u8 *op){
    reg.a = gb_read8(reg.de);
}
/* FA */    void op_ld_reg_a_ind_nn(u8 *op){
    reg.a = gb_read8((op[1] << 8) | op[0]);
}
/* 3E */    void op_ld_reg_a_imm_n(u8 *op){
    reg.a = *op;
}

// 4. LD n,A
/* 47 */    void op_ld_reg_b_reg_a(u8 *op){
    reg.b = reg.a;
}
/* 4F */    void op_ld_reg_c_reg_a(u8 *op){
    reg.c = reg.a;
}
/* 57 */    void op_ld_reg_d_reg_a(u8 *op){
    reg.d = reg.a;
}
/* 5F */    void op_ld_reg_e_reg_a(u8 *op){
    reg.e = reg.a;
}
/* 67 */    void op_ld_reg_h_reg_a(u8 *op){
    reg.h = reg.a;
}
/* 6F */    void op_ld_reg_l_reg_a(u8 *op){
    reg.l = reg.a;
}
/* 02 */    void op_ld_ind_bc_reg_a(u8 *op){
    gb_write8(reg.bc, reg.a);
}
/* 12 */    void op_ld_ind_de_reg_a(u8 *op){
    gb_write8(reg.de, reg.a);
}
/* 77 */    void op_ld_ind_hl_reg_a(u8 *op){
    gb_write8(reg.hl, reg.a);
}
/* EA */    void op_ld_ind_nn_reg_a(u8 *op){
    gb_write8((op[1] << 8) | op[0], reg.a);
}

// 5. LD A,(C)
/* F2 */    void op_ld_reg_a_off_c(u8 *op){
    reg.a = gb_read8((u16) (0xff00 + reg.c));
}

// 6. LD (C),A
/* E2 */    void op_ld_off_c_reg_a(u8 *op){
    gb_write8((u16) (0xff00 + reg.c), reg.a);
}

// 7. LD A,(HLD)
// 8. LD A,(HL-)
// 9. LDD A,(HL)
/* 3A */    void op_ldd_reg_a_ind_hl(u8 *op){
    reg.a = gb_read8(reg.hl--);
}

// 10. LD (HLD),A
// 11. LD (HL-),A
// 12. LDD (HL),A
/* 32 */    void op_ldd_ind_hl_reg_a(u8 *op){
    gb_write8(reg.hl--, reg.a);
}

// 13. LD A,(HLI)
// 14. LD A,(HL+)
// 15. LDI A,(HL)
/* 2A */    void op_ldi_reg_a_ind_hl(u8 *op){
    reg.a = gb_read8(reg.hl++);
}

// 16. LD (HLI),A
// 17. LD (HL+),A
// 18. LDI (HL),A
/* 22 */    void op_ldi_ind_hl_reg_a(u8 *op){
    gb_write8(reg.hl++, reg.a);
}

// 19. LDH (n),A
/* E0 */    void op_ldh_off_n_reg_a(u8 *op){
    gb_write8((u16) (0xff00 + *op), reg.a);
}

// 20. LDH A,(n)
/* F0 */    void op_ldh_reg_a_off_n(u8 *op){
    reg.a = gb_read8((u16)(0xff00 + *op));
}

// 3.3.2. 16-Bit Loads
// 1. LD n,nn
/* 01 */    void ld_reg_bc_imm_nn(u8 *op){
    reg.bc = op[1] << 8 | op[0];
}
/* 11 */    void ld_reg_de_imm_nn(u8 *op){
    reg.de = op[1] << 8 | op[0];
}
/* 21 */    void ld_reg_hl_imm_nn(u8 *op){
    reg.hl = op[1] << 8 | op[0];
}
/* 31 */    void ld_reg_sp_imm_nn(u8 *op){
    reg.sp = op[1] << 8 | op[0];
}

// 2. LD SP,HL
/* F9 */    void op_ld_sp_reg_hl(u8 *op){
    reg.sp = reg.hl;
}

// 3. LD HL,SP+n
// 4. LDHL SP,n
/* F8 */    void op_ldhl_sp_off_n(u8 *op){
    u32 res = reg.sp + *op;
    reg.hl = (u16) res;
    reg.fl.z = 0;
    reg.fl.n = 0;
    reg.fl.h = (reg.sp & 0x0f + (*op) & 0x0f) > 0x0f;
    reg.fl.c = (res & 0xffff0000) != 0;
}

// 5. LD (nn),SP
/* 08 */    void op_ld_imm_nn_sp(u8 *op){
    gb_write16(op[1] << 8 | op[0], reg.sp);
}

// 6. PUSH nn
/* F5 */    void op_push_reg_af(u8 *op){
    reg.sp -= 2;
    gb_write(reg.sp, (u8*)&reg.af, 2);
}
/* C5 */    void op_push_reg_bc(u8 *op){
    reg.sp -= 2;
    gb_write(reg.sp, (u8*)&reg.bc, 2);
}
/* D5 */    void op_push_reg_de(u8 *op){
    reg.sp -= 2;
    gb_write(reg.sp, (u8*)&reg.de, 2);
}
/* E5 */    void op_push_reg_hl(u8 *op){
    reg.sp -= 2;
    gb_write(reg.sp, (u8*)&reg.hl, 2);
}




















/* 00 */    void op_nop(u8 *op){

}