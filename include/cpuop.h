
#ifndef CPUOP_H_
#define CPUOP_H_

#include <stdint.h>

#include "gbreg.h"
#include "gbmem.h"

// 3.3.1. 8-Bit Loads
// 1. LD nn,n
/* 0x06 */	void op_ld_reg_b_imm_n(uint8_t *op);
/* 0x0E */	void op_ld_reg_c_imm_n(uint8_t *op);
/* 0x16 */	void op_ld_reg_d_imm_n(uint8_t *op);
/* 0x1E */	void op_ld_reg_e_imm_n(uint8_t *op);
/* 0x26 */	void op_ld_reg_h_imm_n(uint8_t *op);
/* 0x2E */	void op_ld_reg_l_imm_n(uint8_t *op);

// 2. LD r1,r2
/* 0x7F */	void op_ld_reg_a_reg_a(uint8_t *op);
/* 0x78 */	void op_ld_reg_a_reg_b(uint8_t *op);
/* 0x79 */	void op_ld_reg_a_reg_c(uint8_t *op);
/* 0x7A */	void op_ld_reg_a_reg_d(uint8_t *op);
/* 0x7B */	void op_ld_reg_a_reg_e(uint8_t *op);
/* 0x7C */	void op_ld_reg_a_reg_h(uint8_t *op);
/* 0x7D */	void op_ld_reg_a_reg_l(uint8_t *op);
/* 0x7E */	void op_ld_reg_a_ind_hl(uint8_t *op);
/* 0x40 */	void op_ld_reg_b_reg_b(uint8_t *op);
/* 0x41 */	void op_ld_reg_b_reg_c(uint8_t *op);
/* 0x42 */	void op_ld_reg_b_reg_d(uint8_t *op);
/* 0x43 */	void op_ld_reg_b_reg_e(uint8_t *op);
/* 0x44 */	void op_ld_reg_b_reg_h(uint8_t *op);
/* 0x45 */	void op_ld_reg_b_reg_l(uint8_t *op);
/* 0x46 */	void op_ld_reg_b_ind_hl(uint8_t *op);
/* 0x48 */	void op_ld_reg_c_reg_b(uint8_t *op);
/* 0x49 */	void op_ld_reg_c_reg_c(uint8_t *op);
/* 0x4A */	void op_ld_reg_c_reg_d(uint8_t *op);
/* 0x4B */	void op_ld_reg_c_reg_e(uint8_t *op);
/* 0x4C */	void op_ld_reg_c_reg_h(uint8_t *op);
/* 0x4D */	void op_ld_reg_c_reg_l(uint8_t *op);
/* 0x4E */	void op_ld_reg_c_ind_hl(uint8_t *op);
/* 0x50 */	void op_ld_reg_d_reg_b(uint8_t *op);
/* 0x51 */	void op_ld_reg_d_reg_c(uint8_t *op);
/* 0x52 */	void op_ld_reg_d_reg_d(uint8_t *op);
/* 0x53 */	void op_ld_reg_d_reg_e(uint8_t *op);
/* 0x54 */	void op_ld_reg_d_reg_h(uint8_t *op);
/* 0x55 */	void op_ld_reg_d_reg_l(uint8_t *op);
/* 0x56 */	void op_ld_reg_d_ind_hl(uint8_t *op);
/* 0x58 */	void op_ld_reg_e_reg_b(uint8_t *op);
/* 0x59 */	void op_ld_reg_e_reg_c(uint8_t *op);
/* 0x5A */	void op_ld_reg_e_reg_d(uint8_t *op);
/* 0x5B */	void op_ld_reg_e_reg_e(uint8_t *op);
/* 0x5C */	void op_ld_reg_e_reg_h(uint8_t *op);
/* 0x5D */	void op_ld_reg_e_reg_l(uint8_t *op);
/* 0x5E */	void op_ld_reg_e_ind_hl(uint8_t *op);
/* 0x60 */	void op_ld_reg_h_reg_b(uint8_t *op);
/* 0x61 */	void op_ld_reg_h_reg_c(uint8_t *op);
/* 0x62 */	void op_ld_reg_h_reg_d(uint8_t *op);
/* 0x63 */	void op_ld_reg_h_reg_e(uint8_t *op);
/* 0x64 */	void op_ld_reg_h_reg_h(uint8_t *op);
/* 0x65 */	void op_ld_reg_h_reg_l(uint8_t *op);
/* 0x66 */	void op_ld_reg_h_ind_hl(uint8_t *op);
/* 0x68 */	void op_ld_reg_l_reg_b(uint8_t *op);
/* 0x69 */	void op_ld_reg_l_reg_c(uint8_t *op);
/* 0x6A */	void op_ld_reg_l_reg_d(uint8_t *op);
/* 0x6B */	void op_ld_reg_l_reg_e(uint8_t *op);
/* 0x6C */	void op_ld_reg_l_reg_h(uint8_t *op);
/* 0x6D */	void op_ld_reg_l_reg_l(uint8_t *op);
/* 0x6E */	void op_ld_reg_l_ind_hl(uint8_t *op);
/* 0x70 */	void op_ld_ind_hl_reg_b(uint8_t *op);
/* 0x71 */	void op_ld_ind_hl_reg_c(uint8_t *op);
/* 0x72 */	void op_ld_ind_hl_reg_d(uint8_t *op);
/* 0x73 */	void op_ld_ind_hl_reg_e(uint8_t *op);
/* 0x74 */	void op_ld_ind_hl_reg_h(uint8_t *op);
/* 0x75 */	void op_ld_ind_hl_reg_l(uint8_t *op);
/* 0x36 */	void op_ld_ind_hl_imm_n(uint8_t *op);

// 3. LD A,n (ignore duplicates)
/* 0x0A */  void op_ld_reg_a_ind_bc(uint8_t *op);
/* 0x1A */  void op_ld_reg_a_ind_de(uint8_t *op);
/* 0xFA */  void op_ld_reg_a_ind_nn(uint8_t *op);
/* 0x3E */  void op_ld_reg_a_imm_n(uint8_t *op);

// 4. LD n,A
/* 0x47 */  void op_ld_reg_b_reg_a(uint8_t *op);
/* 0x4F */  void op_ld_reg_c_reg_a(uint8_t *op);
/* 0x57 */  void op_ld_reg_d_reg_a(uint8_t *op);
/* 0x5F */  void op_ld_reg_e_reg_a(uint8_t *op);
/* 0x67 */  void op_ld_reg_h_reg_a(uint8_t *op);
/* 0x6F */  void op_ld_reg_l_reg_a(uint8_t *op);
/* 0x02 */  void op_ld_ind_bc_reg_a(uint8_t *op);
/* 0x12 */  void op_ld_ind_de_reg_a(uint8_t *op);
/* 0x77 */  void op_ld_ind_hl_reg_a(uint8_t *op);
/* 0xEA */  void op_ld_ind_nn_reg_a(uint8_t *op);

/* 0x00 */	void op_nop(uint8_t *op);
#endif /* CPUOP_H_ */
