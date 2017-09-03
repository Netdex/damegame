

#include <gbreg.h>
#include "cpuop.h"

// TODO combine duplicate functions using utility functions

/* 3.3.1. 8-Bit Loads */
// 1. LD nn,n
/* 06 */	void op_ld_reg_b_imm_n(u8 op){ reg.b = op; }
/* 0E */	void op_ld_reg_c_imm_n(u8 op){ reg.c = op; }
/* 16 */	void op_ld_reg_d_imm_n(u8 op){ reg.d = op; }
/* 1E */	void op_ld_reg_e_imm_n(u8 op){ reg.e = op; }
/* 26 */	void op_ld_reg_h_imm_n(u8 op){ reg.h = op; }
/* 2E */	void op_ld_reg_l_imm_n(u8 op){ reg.l = op; }

// 2. LD r1,r2
/* 7F */	void op_ld_reg_a_reg_a(){ reg.a = reg.a; }
/* 78 */	void op_ld_reg_a_reg_b(){ reg.a = reg.b; }
/* 79 */	void op_ld_reg_a_reg_c(){ reg.a = reg.c; }
/* 7A */	void op_ld_reg_a_reg_d(){ reg.a = reg.d; }
/* 7B */	void op_ld_reg_a_reg_e(){ reg.a = reg.e; }
/* 7C */	void op_ld_reg_a_reg_h(){ reg.a = reg.h; }
/* 7D */	void op_ld_reg_a_reg_l(){ reg.a = reg.l; }
/* 7E */	void op_ld_reg_a_ind_hl(){ reg.a = gb_read8(reg.hl); }
/* 40 */	void op_ld_reg_b_reg_b(){ reg.b = reg.b; }
/* 41 */	void op_ld_reg_b_reg_c(){ reg.b = reg.c; }
/* 42 */	void op_ld_reg_b_reg_d(){ reg.b = reg.d; }
/* 43 */	void op_ld_reg_b_reg_e(){ reg.b = reg.e; }
/* 44 */	void op_ld_reg_b_reg_h(){ reg.b = reg.h; }
/* 45 */	void op_ld_reg_b_reg_l(){ reg.b = reg.l; }
/* 46 */	void op_ld_reg_b_ind_hl(){ reg.b = gb_read8(reg.hl); }
/* 48 */	void op_ld_reg_c_reg_b(){ reg.c = reg.b; }
/* 49 */	void op_ld_reg_c_reg_c(){ reg.c = reg.c; }
/* 4A */	void op_ld_reg_c_reg_d(){ reg.c = reg.d; }
/* 4B */	void op_ld_reg_c_reg_e(){ reg.c = reg.e; }
/* 4C */	void op_ld_reg_c_reg_h(){ reg.c = reg.h; }
/* 4D */	void op_ld_reg_c_reg_l(){ reg.c = reg.l; }
/* 4E */	void op_ld_reg_c_ind_hl(){ reg.c = gb_read8(reg.hl); }
/* 50 */	void op_ld_reg_d_reg_b(){ reg.d = reg.b; }
/* 51 */	void op_ld_reg_d_reg_c(){ reg.d = reg.c; }
/* 52 */	void op_ld_reg_d_reg_d(){ reg.d = reg.d; }
/* 53 */	void op_ld_reg_d_reg_e(){ reg.d = reg.e; }
/* 54 */	void op_ld_reg_d_reg_h(){ reg.d = reg.h; }
/* 55 */	void op_ld_reg_d_reg_l(){ reg.d = reg.l; }
/* 56 */	void op_ld_reg_d_ind_hl(){ reg.d = gb_read8(reg.hl); }
/* 58 */	void op_ld_reg_e_reg_b(){ reg.e = reg.b; }
/* 59 */	void op_ld_reg_e_reg_c(){ reg.e = reg.c; }
/* 5A */	void op_ld_reg_e_reg_d(){ reg.e = reg.d; }
/* 5B */	void op_ld_reg_e_reg_e(){ reg.e = reg.e; }
/* 5C */	void op_ld_reg_e_reg_h(){ reg.e = reg.h; }
/* 5D */	void op_ld_reg_e_reg_l(){ reg.e = reg.l; }
/* 5E */	void op_ld_reg_e_ind_hl(){ reg.e = gb_read8(reg.hl); }
/* 60 */	void op_ld_reg_h_reg_b(){ reg.h = reg.b; }
/* 61 */	void op_ld_reg_h_reg_c(){ reg.h = reg.c; }
/* 62 */	void op_ld_reg_h_reg_d(){ reg.h = reg.d; }
/* 63 */	void op_ld_reg_h_reg_e(){ reg.h = reg.e; }
/* 64 */	void op_ld_reg_h_reg_h(){ reg.h = reg.h; }
/* 65 */	void op_ld_reg_h_reg_l(){ reg.h = reg.l; }
/* 66 */	void op_ld_reg_h_ind_hl(){ reg.h = gb_read8(reg.hl); }
/* 68 */	void op_ld_reg_l_reg_b(){ reg.l = reg.b; }
/* 69 */	void op_ld_reg_l_reg_c(){ reg.l = reg.c; }
/* 6A */	void op_ld_reg_l_reg_d(){ reg.l = reg.d; }
/* 6B */	void op_ld_reg_l_reg_e(){ reg.l = reg.e; }
/* 6C */	void op_ld_reg_l_reg_h(){ reg.l = reg.h; }
/* 6D */	void op_ld_reg_l_reg_l(){ reg.l = reg.l; }
/* 6E */	void op_ld_reg_l_ind_hl(){ reg.l = gb_read8(reg.hl); }
/* 70 */	void op_ld_ind_hl_reg_b(){ gb_write8(reg.hl, reg.b); }
/* 71 */	void op_ld_ind_hl_reg_c(){ gb_write8(reg.hl, reg.c); }
/* 72 */	void op_ld_ind_hl_reg_d(){ gb_write8(reg.hl, reg.d); }
/* 73 */	void op_ld_ind_hl_reg_e(){ gb_write8(reg.hl, reg.e); }
/* 74 */	void op_ld_ind_hl_reg_h(){ gb_write8(reg.hl, reg.h); }
/* 75 */	void op_ld_ind_hl_reg_l(){ gb_write8(reg.hl, reg.l); }
/* 36 */    void op_ld_ind_hl_imm_n(u8 op){ gb_write8(reg.hl, op); }

// 3. LD A,n (ignore duplicates)
/* 0A */    void op_ld_reg_a_ind_bc(){ reg.a = gb_read8(reg.bc); }
/* 1A */    void op_ld_reg_a_ind_de(){ reg.a = gb_read8(reg.de); }
/* FA */    void op_ld_reg_a_ind_nn(u16 op){ reg.a = gb_read8(op); }
/* 3E */    void op_ld_reg_a_imm_n(u8 op){ reg.a = op; }

// 4. LD n,A
/* 47 */    void op_ld_reg_b_reg_a(){ reg.b = reg.a; }
/* 4F */    void op_ld_reg_c_reg_a(){ reg.c = reg.a; }
/* 57 */    void op_ld_reg_d_reg_a(){ reg.d = reg.a; }
/* 5F */    void op_ld_reg_e_reg_a(){ reg.e = reg.a; }
/* 67 */    void op_ld_reg_h_reg_a(){ reg.h = reg.a; }
/* 6F */    void op_ld_reg_l_reg_a(){ reg.l = reg.a; }
/* 02 */    void op_ld_ind_bc_reg_a(){ gb_write8(reg.bc, reg.a); }
/* 12 */    void op_ld_ind_de_reg_a(){ gb_write8(reg.de, reg.a); }
/* 77 */    void op_ld_ind_hl_reg_a(){ gb_write8(reg.hl, reg.a); }
/* EA */    void op_ld_ind_nn_reg_a(u16 op){ gb_write8(op, reg.a); }

// 5. LD A,(C)
/* F2 */    void op_ld_reg_a_off_c(){ reg.a = gb_read8((u16) (0xff00 + reg.c)); }

// 6. LD (C),A
/* E2 */    void op_ld_off_c_reg_a(){ gb_write8((u16) (0xff00 + reg.c), reg.a); }

// 7. LD A,(HLD)
// 8. LD A,(HL-)
// 9. LDD A,(HL)
/* 3A */    void op_ldd_reg_a_ind_hl(){ reg.a = gb_read8(reg.hl--); }

// 10. LD (HLD),A
// 11. LD (HL-),A
// 12. LDD (HL),A
/* 32 */    void op_ldd_ind_hl_reg_a(){ gb_write8(reg.hl--, reg.a); }

// 13. LD A,(HLI)
// 14. LD A,(HL+)
// 15. LDI A,(HL)
/* 2A */    void op_ldi_reg_a_ind_hl(){ reg.a = gb_read8(reg.hl++); }

// 16. LD (HLI),A
// 17. LD (HL+),A
// 18. LDI (HL),A
/* 22 */    void op_ldi_ind_hl_reg_a(){ gb_write8(reg.hl++, reg.a); }

// 19. LDH (n),A
/* E0 */    void op_ldh_off_n_reg_a(u8 op){ gb_write8((u16) (0xff00 + op), reg.a); }

// 20. LDH A,(n)
/* F0 */    void op_ldh_reg_a_off_n(u8 op){ reg.a = gb_read8((u16)(0xff00 + op)); }


// 3.3.2. 16-Bit Loads
// 1. LD n,nn
/* 01 */    void ld_reg_bc_imm_nn(u16 op){ reg.bc = op; }
/* 11 */    void ld_reg_de_imm_nn(u16 op){ reg.de = op; }
/* 21 */    void ld_reg_hl_imm_nn(u16 op){ reg.hl = op; }
/* 31 */    void ld_reg_sp_imm_nn(u16 op){ reg.sp = op; }

// 2. LD SP,HL
/* F9 */    void op_ld_sp_reg_hl(){
    reg.sp = reg.hl;
}

// 3. LD HL,SP+n
// 4. LDHL SP,n
/* F8 */    void op_ldhl_sp_off_n(u8 op){
    u32 res = reg.sp + op;
    reg.hl = (u16) res;
    reg.fl.z = 0;
    reg.fl.n = 0;
    reg.fl.h = (reg.sp & 0x0f + (op) & 0x0f) > 0x0f;
    reg.fl.c = (res & 0xffff0000) != 0;
}

// 5. LD (nn),SP
/* 08 */    void op_ld_imm_nn_sp(u16 op){
    gb_write16(op, reg.sp);
}

// 6. PUSH nn
void a_push_reg(u16 val){
    reg.sp -= 2;
    gb_write(reg.sp, (u8*)&val, 2);
}
/* F5 */    void op_push_reg_af(){ a_push_reg(reg.af); }
/* C5 */    void op_push_reg_bc(){ a_push_reg(reg.bc); }
/* D5 */    void op_push_reg_de(){ a_push_reg(reg.de); }
/* E5 */    void op_push_reg_hl(){ a_push_reg(reg.hl); }

// 7. POP nn
void a_pop_reg(u16 *r){
    *r = gb_read16(reg.sp);
    reg.sp += 2;
}
/* F1 */    void op_pop_reg_af() { a_pop_reg(&reg.af); }
/* C1 */    void op_pop_reg_bc(){ a_pop_reg(&reg.bc); }
/* D1 */    void op_pop_reg_de(){ a_pop_reg(&reg.de); }
/* E1 */    void op_pop_reg_hl(){ a_pop_reg(&reg.hl); }

// 3.3.3. 8-Bit ALU
// 1. ADD A,n
void a_add_reg_a(u32 val){
    u32 res = reg.a + val;
    u32 msk = res ^ (reg.a ^ val);
    reg.a = (u8) res;
    reg.fl.z = reg.a == 0;
    reg.fl.n = 0;
    reg.fl.h = (msk & 0x10) != 0;
    reg.fl.c = (msk & 0x100) != 0;
}
/* 87 */    void op_add_reg_a_reg_a(){ a_add_reg_a(reg.a); }
/* 80 */    void op_add_reg_a_reg_b(){ a_add_reg_a(reg.b); }
/* 81 */    void op_add_reg_a_reg_c(){ a_add_reg_a(reg.c); }
/* 82 */    void op_add_reg_a_reg_d(){ a_add_reg_a(reg.d); }
/* 83 */    void op_add_reg_a_reg_e(){ a_add_reg_a(reg.e); }
/* 84 */    void op_add_reg_a_reg_h(){ a_add_reg_a(reg.h); }
/* 85 */    void op_add_reg_a_reg_l(){ a_add_reg_a(reg.l); }
/* 86 */    void op_add_reg_a_ind_hl(){ a_add_reg_a(gb_read8(reg.hl)); }
/* C6 */    void op_add_reg_a_imm_n(u8 op){ a_add_reg_a(op); }

// 2. ADC A,n
void a_adc_reg_a(u32 v){ a_add_reg_a(v + reg.fl.c); }
/* 8F */    void op_adc_reg_a_reg_a(){ a_adc_reg_a(reg.a); }
/* 88 */    void op_adc_reg_a_reg_b(){ a_adc_reg_a(reg.b); }
/* 89 */    void op_adc_reg_a_reg_c(){ a_adc_reg_a(reg.c); }
/* 8A */    void op_adc_reg_a_reg_d(){ a_adc_reg_a(reg.d); }
/* 8B */    void op_adc_reg_a_reg_e(){ a_adc_reg_a(reg.e); }
/* 8C */    void op_adc_reg_a_reg_h(){ a_adc_reg_a(reg.h); }
/* 8D */    void op_adc_reg_a_reg_l(){ a_adc_reg_a(reg.l); }
/* 8E */    void op_adc_reg_a_ind_hl(){ a_adc_reg_a(gb_read8(reg.hl)); }
/* CE */    void op_adc_reg_a_imm_n(u8 op){ a_adc_reg_a(op); }

// 3. SUB n
void a_sub_reg_a(u32 val){ reg.a = a_cp_reg_a(val); }
/* 97 */    void op_sub_reg_a(){ a_sub_reg_a(reg.a); }
/* 90 */    void op_sub_reg_b(){ a_sub_reg_a(reg.b); }
/* 91 */    void op_sub_reg_c(){ a_sub_reg_a(reg.c); }
/* 92 */    void op_sub_reg_d(){ a_sub_reg_a(reg.d); }
/* 93 */    void op_sub_reg_e(){ a_sub_reg_a(reg.e); }
/* 94 */    void op_sub_reg_h(){ a_sub_reg_a(reg.h); }
/* 95 */    void op_sub_reg_l(){ a_sub_reg_a(reg.l); }
/* 96 */    void op_sub_ind_hl(){ a_sub_reg_a(gb_read8(reg.hl)); }
/* D6 */    void op_sub_imm_n(u8 op){ a_sub_reg_a(op); }

// 4. SBC A,n
void a_sbc_reg_a(u32 v){ a_sub_reg_a(v + reg.fl.c); }
/* 9F */    void op_sbc_reg_a_reg_a(){ a_sbc_reg_a(reg.a); }
/* 98 */    void op_sbc_reg_a_reg_b(){ a_sbc_reg_a(reg.b); }
/* 99 */    void op_sbc_reg_a_reg_c(){ a_sbc_reg_a(reg.c); }
/* 9A */    void op_sbc_reg_a_reg_d(){ a_sbc_reg_a(reg.d); }
/* 9B */    void op_sbc_reg_a_reg_e(){ a_sbc_reg_a(reg.e); }
/* 9C */    void op_sbc_reg_a_reg_h(){ a_sbc_reg_a(reg.h); }
/* 9D */    void op_sbc_reg_a_reg_l(){ a_sbc_reg_a(reg.l); }
/* 9E */    void op_sbc_reg_a_ind_hl(){ a_sbc_reg_a(gb_read8(reg.hl)); }
/* ?? */    void op_sbc_reg_a_imm_n(u8 op){ a_sbc_reg_a(op); }

// 5. AND n
void a_and_reg_a(u32 val){
    reg.a &= val;
    reg.fl.z = reg.a == 0;
    reg.fl.n = 0;
    reg.fl.h = 1;
    reg.fl.c = 0;
}
/* A7 */    void op_and_reg_a(){ a_and_reg_a(reg.a); }
/* A0 */    void op_and_reg_b(){ a_and_reg_a(reg.b); }
/* A1 */    void op_and_reg_c(){ a_and_reg_a(reg.c); }
/* A2 */    void op_and_reg_d(){ a_and_reg_a(reg.d); }
/* A3 */    void op_and_reg_e(){ a_and_reg_a(reg.e); }
/* A4 */    void op_and_reg_h(){ a_and_reg_a(reg.h); }
/* A5 */    void op_and_reg_l(){ a_and_reg_a(reg.l); }
/* A6 */    void op_and_ind_hl(){ a_and_reg_a(gb_read8(reg.hl)); }
/* E6 */    void op_and_imm_n(u8 op){ a_and_reg_a(op); }

// 6. OR n
void a_or_reg_a(u32 val){
    reg.a |= val;
    reg.fl.z = reg.a == 0;
    reg.fl.n = 0;
    reg.fl.h = 0;
    reg.fl.c = 0;
}
/* B7 */    void op_or_reg_a(){ a_or_reg_a(reg.a); }
/* B0 */    void op_or_reg_b(){ a_or_reg_a(reg.b); }
/* B1 */    void op_or_reg_c(){ a_or_reg_a(reg.c); }
/* B2 */    void op_or_reg_d(){ a_or_reg_a(reg.d); }
/* B3 */    void op_or_reg_e(){ a_or_reg_a(reg.e); }
/* B4 */    void op_or_reg_h(){ a_or_reg_a(reg.h); }
/* B5 */    void op_or_reg_l(){ a_or_reg_a(reg.l); }
/* B6 */    void op_or_ind_hl(){ a_or_reg_a(gb_read8(reg.hl)); }
/* F6 */    void op_or_imm_n(u8 op){ a_or_reg_a(op); }

// 7. XOR n
void a_xor_reg_a(u32 val){
    reg.a ^= val;
    reg.fl.z = reg.a == 0;
    reg.fl.n = 0;
    reg.fl.h = 0;
    reg.fl.c = 0;
}
/* AF */    void op_xor_reg_a(){ a_xor_reg_a(reg.a); }
/* A8 */    void op_xor_reg_b(){ a_xor_reg_a(reg.b); }
/* A9 */    void op_xor_reg_c(){ a_xor_reg_a(reg.c); }
/* AA */    void op_xor_reg_d(){ a_xor_reg_a(reg.d); }
/* AB */    void op_xor_reg_e(){ a_xor_reg_a(reg.e); }
/* AC */    void op_xor_reg_h(){ a_xor_reg_a(reg.h); }
/* AD */    void op_xor_reg_l(){ a_xor_reg_a(reg.l); }
/* AE */    void op_xor_ind_hl(){ a_xor_reg_a(gb_read8(reg.hl)); }
/* EE */    void op_xor_imm_n(u8 op){ a_xor_reg_a(op); }

// 8. CP n
u8 a_cp_reg_a(u32 val){
    u32 res = reg.a - val;
    u32 msk = res ^ (reg.a ^ val);
    reg.fl.z = reg.a == 0;
    reg.fl.n = 1;
    reg.fl.h = (msk & 0x10) == 0;
    reg.fl.c = (msk & 0x100) == 0;
    return (u8) res;
}
/* BF */    void op_cp_reg_a(){ a_cp_reg_a(reg.a); }
/* B8 */    void op_cp_reg_b(){ a_cp_reg_a(reg.b); }
/* B9 */    void op_cp_reg_c(){ a_cp_reg_a(reg.c); }
/* BA */    void op_cp_reg_d(){ a_cp_reg_a(reg.d); }
/* BB */    void op_cp_reg_e(){ a_cp_reg_a(reg.e); }
/* BC */    void op_cp_reg_h(){ a_cp_reg_a(reg.h); }
/* BD */    void op_cp_reg_l(){ a_cp_reg_a(reg.l); }
/* BE */    void op_cp_ind_hl(){ a_cp_reg_a(gb_read8(reg.hl)); }
/* FE */    void op_cp_imm_n(u8 op){ a_cp_reg_a(op); }

// 9. INC n
void a_inc_reg(u8 *r){
    reg.fl.h = (*r & 0x0f) == 0x0f;
    u32 res = *r + (u32)1;
    *r = (u8) res;
    reg.fl.z = *r == 0;
    reg.fl.n = 0;
}
/* 3C */    void op_inc_reg_a(){ a_inc_reg(&reg.a); }
/* 04 */    void op_inc_reg_b(){ a_inc_reg(&reg.b); }
/* 0C */    void op_inc_reg_c(){ a_inc_reg(&reg.c); }
/* 14 */    void op_inc_reg_d(){ a_inc_reg(&reg.d); }
/* 1C */    void op_inc_reg_e(){ a_inc_reg(&reg.e); }
/* 24 */    void op_inc_reg_h(){ a_inc_reg(&reg.h); }
/* 2C */    void op_inc_reg_l(){ a_inc_reg(&reg.l); }
/* 34 */    void op_inc_ind_hl(){ gb_memptr(reg.hl); }

// 10. DEC n
void a_dec_reg(u8 *r){
    reg.fl.h = (*r & 0x0f) == 0;
    u32 res = *r - (u8)1;
    *r = (u8) res;
    reg.fl.z = *r == 0;
    reg.fl.n = 0;
}
/* 3D */ void op_dec_reg_a(){ a_dec_reg(&reg.a); }
/* 05 */ void op_dec_reg_b(){ a_dec_reg(&reg.b); }
/* 0D */ void op_dec_reg_c(){ a_dec_reg(&reg.c); }
/* 15 */ void op_dec_reg_d(){ a_dec_reg(&reg.d); }
/* 1D */ void op_dec_reg_e(){ a_dec_reg(&reg.e); }
/* 25 */ void op_dec_reg_h(){ a_dec_reg(&reg.h); }
/* 2D */ void op_dec_reg_l(){ a_dec_reg(&reg.l); }
/* 35 */ void op_dec_ind_hl(){ a_dec_reg(gb_memptr(reg.hl)); }

// 3.3.4. 16-Bit Arithmetic
// 1. ADD HL,n
void a_add_reg_hl(u16 val){
    u32 res = reg.hl + val;
    u32 msk = res ^ (reg.hl ^ val);
    reg.hl = (u16) res;
    reg.fl.n = 0;
    reg.fl.h = msk & 0x1000;
    reg.fl.c = msk & 0x10000;
}
/* 09 */    void op_add_reg_hl_reg_bc(){ a_add_reg_hl(reg.bc); }
/* 19 */    void op_add_reg_hl_reg_de(){ a_add_reg_hl(reg.de); }
/* 29 */    void op_add_reg_hl_reg_hl(){ a_add_reg_hl(reg.hl); }
/* 39 */    void op_add_reg_hl_reg_sp(){ a_add_reg_hl(reg.sp); }

// 2. ADD SP,n
/* E8 */    void op_add_reg_sp_imm_n(u8 op){
    u32 res = reg.sp + op;
    u32 msk = res ^ (reg.hl ^ op);
    reg.hl = (u16) res;
    reg.fl.z = 0;
    reg.fl.n = 0;
    reg.fl.h = msk & 0x1000;
    reg.fl.c = msk & 0x10000;
}

// 3. INC nn
/* 03 */    void op_inc_reg_bc(){ ++reg.bc; }
/* 13 */    void op_inc_reg_de(){ ++reg.de; }
/* 23 */    void op_inc_reg_hl(){ ++reg.hl; }
/* 33 */    void op_inc_reg_sp(){ ++reg.sp; }

// 4. DEC nn
/* 0B */    void op_dec_reg_bc(){ --reg.bc; }
/* 1B */    void op_dec_reg_de(){ --reg.de; }
/* 2B */    void op_dec_reg_hl(){ --reg.hl; }
/* 3B */    void op_dec_reg_sp(){ --reg.sp; }






/* 00 */    void op_nop(){}