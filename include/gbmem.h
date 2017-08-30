
#ifndef GBMEM_H_
#define GBMEM_H_

#include <stdint.h>

extern uint8_t mem[];

uint8_t gb_read8(uint16_t addr);
void gb_write8(uint16_t addr, uint8_t value);

uint16_t gb_read16(uint16_t addr);
void gb_write16(uint16_t addr, uint16_t value);

#endif /* GBMEM_H_ */
