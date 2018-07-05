
#include <assert.h>
#include "gbmem.h"

struct {
    u8 pbank[0x4000];   // permanent rom
    u8 sbank[0x4000];   // switchable rom
    u8 vram[0x2000];    // video ram
    u8 sram[0x2000];    // switchable external ram bank
    u8 wbank0[0x2000];  // working ram bank 0
    u8 wbank1[0x2000];  // working ram bank 1
    u8 sat[0x100];      // sprite attribute table
    u8 dev[0x80];       // device mapping
    u8 hram[0x7f];      // high ram
    u8 ier;             // interrupt enable register
} mem;

// TODO implement everything

u8* gb_memptr(u16 addr){
    assert(addr >= 0 && addr <= 0xffff);
    if(addr <  0x4000)   return mem.pbank    + addr;
    if(addr <  0x8000)   return mem.sbank    + addr - 0x4000;
    if(addr <  0xa000)   return mem.vram     + addr - 0x8000;
    if(addr <  0xc000)   return mem.sram     + addr - 0xa000;
    if(addr <  0xd000)   return mem.wbank0   + addr - 0xc000;
    if(addr <  0xe000)   return mem.wbank1   + addr - 0xd000;
    if(addr <  0xf000)   return mem.wbank0   + addr - 0xe000;
    if(addr <  0xfe00)   return mem.wbank1   + addr - 0xf000;
    if(addr <  0xff00)   return mem.sat      + addr - 0xfe00;
    if(addr <  0xff80)   return mem.dev      + addr - 0xfe00;
    if(addr <  0xffff)   return mem.hram     + addr - 0xff80;
    if(addr == 0xffff)   return &mem.ier;
    return NULL;
}

uint8_t gb_read8(u16 addr) {
	return *gb_memptr(addr);
}

void gb_write8(u16 addr, u8 value) {
    *gb_memptr(addr) = value;
}

uint16_t gb_read16(u16 addr){
    return (*gb_memptr(addr)) | (*gb_memptr((u16) (addr + 1)) << 8);
}

void gb_write16(u16 addr, u16 value){
    *gb_memptr(addr) = (u8) (value & 0xff);
    *gb_memptr((u16) (addr + 1)) = (u8) ((value & 0xff00) >> 8);
}

void gb_read(u16 addr, size_t len, u8* dest){
    for(int i = 0; i < len; i++){
        dest[i] = gb_read8((u16) (addr + i));
    }
}

void gb_write(u16 addr, const u8 *src, size_t len){
    for(int i = 0; i < len; i++){
        gb_write8((u16) (addr + i), src[i]);
    }
}

