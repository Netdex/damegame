#ifndef INCLUDE_GBCPU_H_
#define INCLUDE_GBCPU_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "gbreg.h"
#include "cpuinst.h"
#include "bootrom.h"
#include "cpuop.h"
#include "gbmem.h"

void gb_init();
void gb_reset();
void gb_load();

void gb_step();



#endif /* INCLUDE_GBCPU_H_ */
