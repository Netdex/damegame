
#ifndef CPUOP_H_
#define CPUOP_H_

#include <stdint.h>

#include "gbreg.h"
#include "gbmem.h"
#include "types.h"

// 3.3.1. 8-Bit Loads
// 1. LD nn,n
/* 06 */	void op_ld_reg_b_imm_n(u8);
/* 0E */	void op_ld_reg_c_imm_n(u8);
/* 16 */	void op_ld_reg_d_imm_n(u8);
/* 1E */	void op_ld_reg_e_imm_n(u8);
/* 26 */	void op_ld_reg_h_imm_n(u8);
/* 2E */	void op_ld_reg_l_imm_n(u8);

// 2. LD r1,r2
/* 7F */	void op_ld_reg_a_reg_a();
/* 78 */	void op_ld_reg_a_reg_b();
/* 79 */	void op_ld_reg_a_reg_c();
/* 7A */	void op_ld_reg_a_reg_d();
/* 7B */	void op_ld_reg_a_reg_e();
/* 7C */	void op_ld_reg_a_reg_h();
/* 7D */	void op_ld_reg_a_reg_l();
/* 7E */	void op_ld_reg_a_ind_hl();
/* 40 */	void op_ld_reg_b_reg_b();
/* 41 */	void op_ld_reg_b_reg_c();
/* 42 */	void op_ld_reg_b_reg_d();
/* 43 */	void op_ld_reg_b_reg_e();
/* 44 */	void op_ld_reg_b_reg_h();
/* 45 */	void op_ld_reg_b_reg_l();
/* 46 */	void op_ld_reg_b_ind_hl();
/* 48 */	void op_ld_reg_c_reg_b();
/* 49 */	void op_ld_reg_c_reg_c();
/* 4A */	void op_ld_reg_c_reg_d();
/* 4B */	void op_ld_reg_c_reg_e();
/* 4C */	void op_ld_reg_c_reg_h();
/* 4D */	void op_ld_reg_c_reg_l();
/* 4E */	void op_ld_reg_c_ind_hl();
/* 50 */	void op_ld_reg_d_reg_b();
/* 51 */	void op_ld_reg_d_reg_c();
/* 52 */	void op_ld_reg_d_reg_d();
/* 53 */	void op_ld_reg_d_reg_e();
/* 54 */	void op_ld_reg_d_reg_h();
/* 55 */	void op_ld_reg_d_reg_l();
/* 56 */	void op_ld_reg_d_ind_hl();
/* 58 */	void op_ld_reg_e_reg_b();
/* 59 */	void op_ld_reg_e_reg_c();
/* 5A */	void op_ld_reg_e_reg_d();
/* 5B */	void op_ld_reg_e_reg_e();
/* 5C */	void op_ld_reg_e_reg_h();
/* 5D */	void op_ld_reg_e_reg_l();
/* 5E */	void op_ld_reg_e_ind_hl();
/* 60 */	void op_ld_reg_h_reg_b();
/* 61 */	void op_ld_reg_h_reg_c();
/* 62 */	void op_ld_reg_h_reg_d();
/* 63 */	void op_ld_reg_h_reg_e();
/* 64 */	void op_ld_reg_h_reg_h();
/* 65 */	void op_ld_reg_h_reg_l();
/* 66 */	void op_ld_reg_h_ind_hl();
/* 68 */	void op_ld_reg_l_reg_b();
/* 69 */	void op_ld_reg_l_reg_c();
/* 6A */	void op_ld_reg_l_reg_d();
/* 6B */	void op_ld_reg_l_reg_e();
/* 6C */	void op_ld_reg_l_reg_h();
/* 6D */	void op_ld_reg_l_reg_l();
/* 6E */	void op_ld_reg_l_ind_hl();
/* 70 */	void op_ld_ind_hl_reg_b();
/* 71 */	void op_ld_ind_hl_reg_c();
/* 72 */	void op_ld_ind_hl_reg_d();
/* 73 */	void op_ld_ind_hl_reg_e();
/* 74 */	void op_ld_ind_hl_reg_h();
/* 75 */	void op_ld_ind_hl_reg_l();
/* 36 */	void op_ld_ind_hl_imm_n(u8);

// 3. LD A,n (ignore duplicates)
/* 0A */    void op_ld_reg_a_ind_bc();
/* 1A */    void op_ld_reg_a_ind_de();
/* FA */    void op_ld_reg_a_ind_nn(u16);
/* 3E */    void op_ld_reg_a_imm_n(u8);

// 4. LD n,A
/* 47 */    void op_ld_reg_b_reg_a();
/* 4F */    void op_ld_reg_c_reg_a();
/* 57 */    void op_ld_reg_d_reg_a();
/* 5F */    void op_ld_reg_e_reg_a();
/* 67 */    void op_ld_reg_h_reg_a();
/* 6F */    void op_ld_reg_l_reg_a();
/* 02 */    void op_ld_ind_bc_reg_a();
/* 12 */    void op_ld_ind_de_reg_a();
/* 77 */    void op_ld_ind_hl_reg_a();
/* EA */    void op_ld_ind_nn_reg_a(u16);

// 5. LD A,(C)
/* F2 */    void op_ld_reg_a_off_c();

// 6. LD (C),A
/* E2 */    void op_ld_off_c_reg_a();

// 7. LD A,(HLD)
// 8. LD A,(HL-)
// 9. LDD A,(HL)
/* 3A */    void op_ldd_reg_a_ind_hl();

// 10. LD (HLD),A
// 11. LD (HL-),A
// 12. LDD (HL),A
/* 32 */    void op_ldd_ind_hl_reg_a();

// 13. LD A,(HLI)
// 14. LD A,(HL+)
// 15. LDI A,(HL)
/* 2A */    void op_ldi_reg_a_ind_hl();

// 16. LD (HLI),A
// 17. LD (HL+),A
// 18. LDI (HL),A
/* 22 */    void op_ldi_ind_hl_reg_a();

// 19. LDH (n),A
/* E0 */    void op_ldh_off_n_reg_a(u8);

// 20. LDH A,(n)
/* F0 */    void op_ldh_reg_a_off_n(u8);

// 3.3.2. 16-Bit Loads
// 1. LD n,nn
/* 01 */    void ld_reg_bc_imm_nn(u16);
/* 11 */    void ld_reg_de_imm_nn(u16);
/* 21 */    void ld_reg_hl_imm_nn(u16);
/* 31 */    void ld_reg_sp_imm_nn(u16);

// 2. LD SP,HL
/* F9 */    void op_ld_sp_reg_hl();

// 3. LD HL,SP+n
// 4. LDHL SP,n
/* F8 */    void op_ldhl_sp_off_n(u8);

// 5. LD (nn),SP
/* 08 */    void op_ld_imm_nn_sp(u16);

// 6. PUSH nn
void a_push_reg(u16 val);
/* F5 */    void op_push_reg_af();
/* C5 */    void op_push_reg_bc();
/* D5 */    void op_push_reg_de();
/* E5 */    void op_push_reg_hl();

// 7. POP nn
void a_pop_reg(u16 *r);
/* F1 */    void op_pop_reg_af();
/* C1 */    void op_pop_reg_bc();
/* D1 */    void op_pop_reg_de();
/* E1 */    void op_pop_reg_hl();

// 3.3.3. 8-Bit ALU
// 1. ADD A,n
void a_add_reg_a(u32 val);
/* 87 */    void op_add_reg_a_reg_a();
/* 80 */    void op_add_reg_a_reg_b();
/* 81 */    void op_add_reg_a_reg_c();
/* 82 */    void op_add_reg_a_reg_d();
/* 83 */    void op_add_reg_a_reg_e();
/* 84 */    void op_add_reg_a_reg_h();
/* 85 */    void op_add_reg_a_reg_l();
/* 86 */    void op_add_reg_a_ind_hl();
/* C6 */    void op_add_reg_a_imm_n(u8);

// 2. ADC A,n
void a_adc_reg_a(u32 v);
/* 8F */    void op_adc_reg_a_reg_a();
/* 88 */    void op_adc_reg_a_reg_b();
/* 89 */    void op_adc_reg_a_reg_c();
/* 8A */    void op_adc_reg_a_reg_d();
/* 8B */    void op_adc_reg_a_reg_e();
/* 8C */    void op_adc_reg_a_reg_h();
/* 8D */    void op_adc_reg_a_reg_l();
/* 8E */    void op_adc_reg_a_ind_hl();
/* CE */    void op_adc_reg_a_imm_n(u8);

// 3. SUB n
void a_sub_reg_a(u32 val);
/* 97 */    void op_sub_reg_a();
/* 90 */    void op_sub_reg_b();
/* 91 */    void op_sub_reg_c();
/* 92 */    void op_sub_reg_d();
/* 93 */    void op_sub_reg_e();
/* 94 */    void op_sub_reg_h();
/* 95 */    void op_sub_reg_l();
/* 96 */    void op_sub_ind_hl();
/* D6 */    void op_sub_imm_n(u8);

// 4. SBC A,n
void a_sbc_reg_a(u32 val);
/* 9F */    void op_sbc_reg_a_reg_a();
/* 98 */    void op_sbc_reg_a_reg_b();
/* 99 */    void op_sbc_reg_a_reg_c();
/* 9A */    void op_sbc_reg_a_reg_d();
/* 9B */    void op_sbc_reg_a_reg_e();
/* 9C */    void op_sbc_reg_a_reg_h();
/* 9D */    void op_sbc_reg_a_reg_l();
/* 9E */    void op_sbc_reg_a_ind_hl();
/* ?? */    void op_sbc_reg_a_imm_n(u8);

// 5. AND n
void a_and_reg_a(u32 val);
/* A7 */    void op_and_reg_a();
/* A0 */    void op_and_reg_b();
/* A1 */    void op_and_reg_c();
/* A2 */    void op_and_reg_d();
/* A3 */    void op_and_reg_e();
/* A4 */    void op_and_reg_h();
/* A5 */    void op_and_reg_l();
/* A6 */    void op_and_ind_hl();
/* E6 */    void op_and_imm_n(u8);

// 6. OR n
void a_or_reg_a(u32 val);
/* B7 */    void op_or_reg_a();
/* B0 */    void op_or_reg_b();
/* B1 */    void op_or_reg_c();
/* B2 */    void op_or_reg_d();
/* B3 */    void op_or_reg_e();
/* B4 */    void op_or_reg_h();
/* B5 */    void op_or_reg_l();
/* B6 */    void op_or_ind_hl();
/* F6 */    void op_or_imm_n(u8);

// 7. XOR n
void a_xor_reg_a(u32 val);
/* AF */    void op_xor_reg_a();
/* A8 */    void op_xor_reg_b();
/* A9 */    void op_xor_reg_c();
/* AA */    void op_xor_reg_d();
/* AB */    void op_xor_reg_e();
/* AC */    void op_xor_reg_h();
/* AD */    void op_xor_reg_l();
/* AE */    void op_xor_ind_hl();
/* EE */    void op_xor_imm_n(u8);

// 8. CP n
u8 a_cp_reg_a(u32 val);
/* BF */    void op_cp_reg_a();
/* B8 */    void op_cp_reg_b();
/* B9 */    void op_cp_reg_c();
/* BA */    void op_cp_reg_d();
/* BB */    void op_cp_reg_e();
/* BC */    void op_cp_reg_h();
/* BD */    void op_cp_reg_l();
/* BE */    void op_cp_ind_hl();
/* FE */    void op_cp_imm_n(u8);

// 9. INC n
void a_inc_reg(u8 *r);
/* 3C */    void op_inc_reg_a();
/* 04 */    void op_inc_reg_b();
/* 0C */    void op_inc_reg_c();
/* 14 */    void op_inc_reg_d();
/* 1C */    void op_inc_reg_e();
/* 24 */    void op_inc_reg_h();
/* 2C */    void op_inc_reg_l();
/* 34 */    void op_inc_ind_hl();

// 10. DEC n
void a_dec_reg(u8 *r);
/* 3D */ void op_dec_reg_a();
/* 05 */ void op_dec_reg_b();
/* 0D */ void op_dec_reg_c();
/* 15 */ void op_dec_reg_d();
/* 1D */ void op_dec_reg_e();
/* 25 */ void op_dec_reg_h();
/* 2D */ void op_dec_reg_l();
/* 35 */ void op_dec_ind_hl();

// 3.3.4. 16-Bit Arithmetic
// 1. ADD HL,n
void a_add_reg_hl(u16 val);
/* 09 */    void op_add_reg_hl_reg_bc();
/* 19 */    void op_add_reg_hl_reg_de();
/* 29 */    void op_add_reg_hl_reg_hl();
/* 39 */    void op_add_reg_hl_reg_sp();

// 2. ADD SP,n
/* E8 */    void op_add_reg_sp_imm_n(u8);

// 3. INC nn
/* 03 */    void op_inc_reg_bc();
/* 13 */    void op_inc_reg_de();
/* 23 */    void op_inc_reg_hl();
/* 33 */    void op_inc_reg_sp();

// 4. DEC nn
/* 0B */    void op_dec_reg_bc();
/* 1B */    void op_dec_reg_de();
/* 2B */    void op_dec_reg_hl();
/* 3B */    void op_dec_reg_sp();

// 3.3.5. Miscellaneous
// CB
void op_cb();
// 1. SWAP n
void a_swap_reg(u8 *r);
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */






/* 00 */    void op_nop();
#endif /* CPUOP_H_ */
