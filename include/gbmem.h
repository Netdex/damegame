
#ifndef GBMEM_H_
#define GBMEM_H_

#include <stdint.h>
#include <stddef.h>
#include "types.h"

extern u8 mem[];

u8* gb_memptr(u16 addr);

u8 gb_read8(u16 addr);
void gb_write8(u16 addr, u8 value);

u16 gb_read16(u16 addr);
void gb_write16(u16 addr, u16 value);

void gb_read(u16 addr, size_t len, u8* dest);
void gb_write(u16 addr, u8 *src, size_t len);



#endif /* GBMEM_H_ */
