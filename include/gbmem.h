
#ifndef GBMEM_H_
#define GBMEM_H_

#include <stdint.h>
#include <stddef.h>
#include "types.h"
#include "gbcart.h"

#define TIMA    0xFF05  // timer address
#define TMA     0xFF06  // timer modulator address (reset)
#define TMC     0xFF07  // timer controller address (freq)

extern gbcart_t cart;

void gb_meminit();

// Obtain pointer to real memory location from virtual address
u8* gb_memptr(u16 addr);

u8 gb_read8(u16 addr);
void gb_write8(u16 addr, u8 value);

u16 gb_read16(u16 addr);
void gb_write16(u16 addr, u16 value);

void gb_read(u16 addr, size_t len, u8* dest);
void gb_write(u16 addr, const u8 *src, size_t len);

void gb_memset(u16 addr, u8 val, size_t len);


#endif /* GBMEM_H_ */
