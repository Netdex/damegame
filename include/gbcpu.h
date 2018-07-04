#ifndef INCLUDE_GBCPU_H_
#define INCLUDE_GBCPU_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "cpuinst.h"

extern bool gb_do_interrupt;

void gb_init();
void gb_reset();
void gb_load(u8 *rom, size_t sz);

cpuinst* gb_step();
void gb_inst_run(u8 opcode, cpuinst *inst);
void gb_printreg();


#endif /* INCLUDE_GBCPU_H_ */
