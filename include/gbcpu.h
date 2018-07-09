#ifndef INCLUDE_GBCPU_H_
#define INCLUDE_GBCPU_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "cpuinst.h"
#include "gbcart.h"

#define CLOCKSPEED  4194304

#define IRQ_VBLANK  (1<<0)
#define IRQ_LCD     (1<<1)
#define IRQ_TIMER   (1<<2)
#define IRQ_JOYPAD  (1<<4)

#define DIVIDER_CYCLES  256
#define SCANLINE_CYCLES 456

#define LCD_MODE2_BOUNDS    376
#define LCD_MODE3_BOUNDS    204

struct {
    u16 addr;
    u8 val;
} gb_init_mem[] = {
        {0xff05, 0x00}, {0xff06, 0x00}, {0xff07, 0x00},
        {0xff10, 0x80}, {0xff11, 0xbf}, {0xff12, 0xf3},
        {0xff14, 0xbf}, {0xff16, 0x3f}, {0xff17, 0x00},
        {0xff19, 0xbf}, {0xff1a, 0x7f}, {0xff1b, 0xff},
        {0xff1c, 0x9f}, {0xff1e, 0xbf}, {0xff20, 0xff},
        {0xff21, 0x00}, {0xff22, 0x00}, {0xff23, 0xbf},
        {0xff24, 0x77}, {0xff25, 0xf3}, {0xff26, 0xf1},
        {0xff40, 0x91}, {0xff42, 0x00}, {0xff43, 0x00},
        {0xff45, 0x00}, {0xff47, 0xfc}, {0xff48, 0xff},
        {0xff49, 0xff}, {0xff4a, 0x00}, {0xff4b, 0x00},
        {0xffff, 0x00}
};

void gb_init();
void gb_reset();
void gb_load(u8 *rom, size_t sz);

void gb_update(int cycles);
cpuinst* gb_step();
void gb_inst_run(u8 opcode, cpuinst *inst);
void gb_printreg();

void gb_update_timer(int cycles);
void gb_update_gfx(int cycles);
void gb_do_interrupt();
void gb_req_interrupt(u8 irq);

#endif /* INCLUDE_GBCPU_H_ */
