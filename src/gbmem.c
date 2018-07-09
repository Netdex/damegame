
#include <assert.h>
#include <gbreg.h>
#include <bootrom.h>
#include <gbcart.h>
#include "gbmem.h"
#include "gbcpu.h"

gbcart_t cart;
gbmem_t mem;

void gb_meminit() {
    gb_write(0, bootrom, 256);
    reg.pc = 0x100;
    reg.af = 0x01b0;
    reg.bc = 0x0013;
    reg.de = 0x00d8;
    reg.hl = 0x014d;
    reg.sp = 0xfffe;
    for (int i = 0; i < sizeof(gb_init_mem) / sizeof(gb_init_mem[0]); ++i) {
        gb_write8(gb_init_mem[i].addr, gb_init_mem[i].val);
    }
}

u8 *gb_memptr(u16 addr) {
    assert(addr >= 0 && addr <= 0xffff);
    if (addr < 0x4000) return mem.pbank + addr;
    if (addr < 0x8000) return cart.mem + cart.romIdx * 0x4000 + addr - 0x4000;
    if (addr < 0xa000) return mem.vram + addr - 0x8000;
    if (addr < 0xc000) return cart.ram + cart.ramIdx * 0x2000 + addr - 0xa000;
    if (addr < 0xd000) return mem.wbank0 + addr - 0xc000;
    if (addr < 0xe000) return mem.wbank1 + addr - 0xd000;
    if (addr < 0xf000) return mem.wbank0 + addr - 0xe000;
    if (addr < 0xfe00) return mem.wbank1 + addr - 0xf000;
    if (addr < 0xff00) return mem.sat + addr - 0xfe00;
    if (addr < 0xff80) return mem.dev + addr - 0xfe00;
    if (addr < 0xffff) return mem.hram + addr - 0xff80;
    if (addr == 0xffff) return &mem.ier;
    return NULL;
}

uint8_t gb_read8(u16 addr) {
    return *gb_memptr(addr);
}

void gb_write8(u16 addr, u8 value) {
    // handle banking writes to ROM
    // this is the most likely place something was implemented wrong
    if (addr < 0x2000 && (cart.mbc == 1 || cart.mbc == 2)) {
        if (cart.mbc == 2 && (addr & (1 << 4))) {
            return;
        }
        // rambank enable
        u8 b = (u8) (value & 0xf);
        if (b == 0xa)
            cart.useRam = true;
        else if (b == 0)
            cart.useRam = false;
    } else if (addr < 0x4000) {
        if (cart.mbc == 2) {
            // rombank change
            cart.romIdx = (u8) (value & 0xf);
        } else if (cart.mbc == 1) {
            // lo rombank change
            cart.romIdx = (u8) ((cart.romIdx & 224) | (value & 31));
        }
        if (cart.romIdx == 0)
            cart.romIdx = 1;
    } else if (addr < 0x6000 && cart.mbc == 1) {
        if (cart.mbc == 1) {
            if (cart.useRombank) {
                // hi rombank change
                cart.romIdx = (u8) ((cart.romIdx & 31) | (value & 224));
                if (cart.romIdx == 0)
                    cart.romIdx = 1;
            } else {
                // rambank change
                cart.ramIdx = (u8) (value & 0x3);
            }
        }
    } else if (addr < 0x8000) {
        if (cart.mbc == 1) {
            cart.useRombank = (value & 1) == 0;
            if (cart.useRombank)
                cart.ramIdx = 0;
        }
    } else if (addr == DIV_REG) {
        // divider register clear
        mem.raw[0xff04] = 0;
    } else if (addr == SCAN_LN) {
        mem.raw[0xff44] = 0;
    } else if (addr == DMA_XFR) {
        u16 iaddr = value << 8;
        for (int i = 0; i < 0xa0; i++) {
            gb_write8((u16) (0xfe00 + i), gb_read8((u16) (iaddr + i)));
        }
    } else {
        if (addr < 0xa000 || addr >= 0xc000 || cart.useRam)
            *gb_memptr(addr) = value;
    }
}

uint16_t gb_read16(u16 addr) {
    return (*gb_memptr(addr)) | (*gb_memptr((u16) (addr + 1)) << 8);
}

void gb_write16(u16 addr, u16 value) {
    *gb_memptr(addr) = (u8) (value & 0xff);
    *gb_memptr((u16) (addr + 1)) = (u8) ((value & 0xff00) >> 8);
}

void gb_read(u16 addr, size_t len, u8 *dest) {
    for (int i = 0; i < len; i++) {
        dest[i] = gb_read8((u16) (addr + i));
    }
}

void gb_write(u16 addr, const u8 *src, size_t len) {
    for (int i = 0; i < len; i++) {
        gb_write8((u16) (addr + i), src[i]);
    }
}

void gb_memset(u16 addr, u8 val, size_t len) {
    for (int i = 0; i < len; i++) {
        gb_write8((u16) (addr + i), val);
    }
}



