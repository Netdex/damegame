//
// Created by netdex on 7/5/2018.
//

#ifndef DAMEGAME_GBCART_H
#define DAMEGAME_GBCART_H

#include <stdio.h>
#include <stdbool.h>
#include "types.h"

#define MBC 0x147
#define NRB 0x148

typedef struct {
    u8 mem[0x200000];
    size_t memSize;

    u8 mbc;             // 0: no memory banking, 1: MBC1, 2: MBC2

    u8 romIdx;          // current rombank

    u8 ramCount;            // number of rambanks (max 4)
    u8 ram[0x8000];     // rambank memory
    u8 ramIdx;          // current rambank

    bool useRam;
    bool useRombank;
} gbcart_t;

bool gb_load_cart(const char* file, gbcart_t *cart);

#endif //DAMEGAME_GBCART_H
