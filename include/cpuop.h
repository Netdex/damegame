
#ifndef CPUOP_H_
#define CPUOP_H_

#include <stdint.h>

#include "gbreg.h"
#include "gbmem.h"
#include "types.h"

// 3.3.1. 8-Bit Loads
// 1. LD nn,n
/* 06 */	void op_ld_reg_b_imm_n(u8 *op);
/* 0E */	void op_ld_reg_c_imm_n(u8 *op);
/* 16 */	void op_ld_reg_d_imm_n(u8 *op);
/* 1E */	void op_ld_reg_e_imm_n(u8 *op);
/* 26 */	void op_ld_reg_h_imm_n(u8 *op);
/* 2E */	void op_ld_reg_l_imm_n(u8 *op);

// 2. LD r1,r2
/* 7F */	void op_ld_reg_a_reg_a(u8 *op);
/* 78 */	void op_ld_reg_a_reg_b(u8 *op);
/* 79 */	void op_ld_reg_a_reg_c(u8 *op);
/* 7A */	void op_ld_reg_a_reg_d(u8 *op);
/* 7B */	void op_ld_reg_a_reg_e(u8 *op);
/* 7C */	void op_ld_reg_a_reg_h(u8 *op);
/* 7D */	void op_ld_reg_a_reg_l(u8 *op);
/* 7E */	void op_ld_reg_a_ind_hl(u8 *op);
/* 40 */	void op_ld_reg_b_reg_b(u8 *op);
/* 41 */	void op_ld_reg_b_reg_c(u8 *op);
/* 42 */	void op_ld_reg_b_reg_d(u8 *op);
/* 43 */	void op_ld_reg_b_reg_e(u8 *op);
/* 44 */	void op_ld_reg_b_reg_h(u8 *op);
/* 45 */	void op_ld_reg_b_reg_l(u8 *op);
/* 46 */	void op_ld_reg_b_ind_hl(u8 *op);
/* 48 */	void op_ld_reg_c_reg_b(u8 *op);
/* 49 */	void op_ld_reg_c_reg_c(u8 *op);
/* 4A */	void op_ld_reg_c_reg_d(u8 *op);
/* 4B */	void op_ld_reg_c_reg_e(u8 *op);
/* 4C */	void op_ld_reg_c_reg_h(u8 *op);
/* 4D */	void op_ld_reg_c_reg_l(u8 *op);
/* 4E */	void op_ld_reg_c_ind_hl(u8 *op);
/* 50 */	void op_ld_reg_d_reg_b(u8 *op);
/* 51 */	void op_ld_reg_d_reg_c(u8 *op);
/* 52 */	void op_ld_reg_d_reg_d(u8 *op);
/* 53 */	void op_ld_reg_d_reg_e(u8 *op);
/* 54 */	void op_ld_reg_d_reg_h(u8 *op);
/* 55 */	void op_ld_reg_d_reg_l(u8 *op);
/* 56 */	void op_ld_reg_d_ind_hl(u8 *op);
/* 58 */	void op_ld_reg_e_reg_b(u8 *op);
/* 59 */	void op_ld_reg_e_reg_c(u8 *op);
/* 5A */	void op_ld_reg_e_reg_d(u8 *op);
/* 5B */	void op_ld_reg_e_reg_e(u8 *op);
/* 5C */	void op_ld_reg_e_reg_h(u8 *op);
/* 5D */	void op_ld_reg_e_reg_l(u8 *op);
/* 5E */	void op_ld_reg_e_ind_hl(u8 *op);
/* 60 */	void op_ld_reg_h_reg_b(u8 *op);
/* 61 */	void op_ld_reg_h_reg_c(u8 *op);
/* 62 */	void op_ld_reg_h_reg_d(u8 *op);
/* 63 */	void op_ld_reg_h_reg_e(u8 *op);
/* 64 */	void op_ld_reg_h_reg_h(u8 *op);
/* 65 */	void op_ld_reg_h_reg_l(u8 *op);
/* 66 */	void op_ld_reg_h_ind_hl(u8 *op);
/* 68 */	void op_ld_reg_l_reg_b(u8 *op);
/* 69 */	void op_ld_reg_l_reg_c(u8 *op);
/* 6A */	void op_ld_reg_l_reg_d(u8 *op);
/* 6B */	void op_ld_reg_l_reg_e(u8 *op);
/* 6C */	void op_ld_reg_l_reg_h(u8 *op);
/* 6D */	void op_ld_reg_l_reg_l(u8 *op);
/* 6E */	void op_ld_reg_l_ind_hl(u8 *op);
/* 70 */	void op_ld_ind_hl_reg_b(u8 *op);
/* 71 */	void op_ld_ind_hl_reg_c(u8 *op);
/* 72 */	void op_ld_ind_hl_reg_d(u8 *op);
/* 73 */	void op_ld_ind_hl_reg_e(u8 *op);
/* 74 */	void op_ld_ind_hl_reg_h(u8 *op);
/* 75 */	void op_ld_ind_hl_reg_l(u8 *op);
/* 36 */	void op_ld_ind_hl_imm_n(u8 *op);

// 3. LD A,n (ignore duplicates)
/* 0A */    void op_ld_reg_a_ind_bc(u8 *op);
/* 1A */    void op_ld_reg_a_ind_de(u8 *op);
/* FA */    void op_ld_reg_a_ind_nn(u8 *op);
/* 3E */    void op_ld_reg_a_imm_n(u8 *op);

// 4. LD n,A
/* 47 */    void op_ld_reg_b_reg_a(u8 *op);
/* 4F */    void op_ld_reg_c_reg_a(u8 *op);
/* 57 */    void op_ld_reg_d_reg_a(u8 *op);
/* 5F */    void op_ld_reg_e_reg_a(u8 *op);
/* 67 */    void op_ld_reg_h_reg_a(u8 *op);
/* 6F */    void op_ld_reg_l_reg_a(u8 *op);
/* 02 */    void op_ld_ind_bc_reg_a(u8 *op);
/* 12 */    void op_ld_ind_de_reg_a(u8 *op);
/* 77 */    void op_ld_ind_hl_reg_a(u8 *op);
/* EA */    void op_ld_ind_nn_reg_a(u8 *op);

// 5. LD A,(C)
/* F2 */    void op_ld_reg_a_off_c(u8 *op);

// 6. LD (C),A
/* E2 */    void op_ld_off_c_reg_a(u8 *op);

// 7. LD A,(HLD)
// 8. LD A,(HL-)
// 9. LDD A,(HL)
/* 3A */    void op_ldd_reg_a_ind_hl(u8 *op);

// 10. LD (HLD),A
// 11. LD (HL-),A
// 12. LDD (HL),A
/* 32 */    void op_ldd_ind_hl_reg_a(u8 *op);

// 13. LD A,(HLI)
// 14. LD A,(HL+)
// 15. LDI A,(HL)
/* 2A */    void op_ldi_reg_a_ind_hl(u8 *op);

// 16. LD (HLI),A
// 17. LD (HL+),A
// 18. LDI (HL),A
/* 22 */    void op_ldi_ind_hl_reg_a(u8 *op);

// 19. LDH (n),A
/* E0 */    void op_ldh_off_n_reg_a(u8 *op);

// 20. LDH A,(n)
/* F0 */    void op_ldh_reg_a_off_n(u8 *op);

// 3.3.2. 16-Bit Loads
// 1. LD n,nn
/* 01 */    void ld_reg_bc_imm_nn(u8 *op);
/* 11 */    void ld_reg_de_imm_nn(u8 *op);
/* 21 */    void ld_reg_hl_imm_nn(u8 *op);
/* 31 */    void ld_reg_sp_imm_nn(u8 *op);

// 2. LD SP,HL
/* F9 */    void op_ld_sp_reg_hl(u8 *op);

// 3. LD HL,SP+n
// 4. LDHL SP,n
/* F8 */    void op_ldhl_sp_off_n(u8 *op);

// 5. LD (nn),SP
/* 08 */    void op_ld_imm_nn_sp(u8 *op);

// 6. PUSH nn
/* F5 */    void op_push_reg_af(u8 *op);
/* C5 */    void op_push_reg_bc(u8 *op);
/* D5 */    void op_push_reg_de(u8 *op);
/* E5 */    void op_push_reg_hl(u8 *op);

















/* 00 */    void op_nop(u8 *op);
#endif /* CPUOP_H_ */
