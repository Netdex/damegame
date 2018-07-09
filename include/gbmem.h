
#ifndef GBMEM_H_
#define GBMEM_H_

#include <stdint.h>
#include <stddef.h>
#include "types.h"
#include "gbcart.h"

#define DIV_REG 0xff04
#define TIMA    0xff05  // timer address
#define TMA     0xff06  // timer modulator address (reset)
#define TMC     0xff07  // timer controller address (freq)
#define IRQ_REG 0xff0f
#define IRQ_EN  0xffff

typedef union {
    struct {
        u8 pbank[0x4000];   // permanent rom
        u8 sbank[0x4000];   // switchable rom
        u8 vram[0x2000];    // video ram
        u8 _sram[0x2000];   // switchable external ram bank (padding)
        u8 wbank0[0x2000];  // working ram bank 0
        u8 wbank1[0x2000];  // working ram bank 1
        u8 sat[0x100];      // sprite attribute table
        u8 dev[0x80];       // device mapping
        u8 hram[0x7f];      // high ram
        u8 ier;             // interrupt enable register
    };
    u8 raw[0xffff];
} gbmem_t;

extern gbmem_t mem;
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
