//
// Created by netdex on 7/5/2018.
//

#include <string.h>
#include "gbcart.h"

bool gb_load_cart(const char *file, gbcart_t *cart) {
    FILE *cartFile = fopen(file, "rb");

    // load cart into memory from file
    u8 *mem = cart->mem;
    int read;
    while((read = fread(mem, 1, 256, cartFile)) > 0){
        mem += read;
        if(mem - cart->mem > 0x200000)
            return false;
    }
    cart->memSize = mem - cart->mem;

    // read mbc flag
    if(cart->mem[MBC] == 0){
        cart->mbc = 0;
    } else if(cart->mem[MBC] >= 1 && cart->mem[MBC] <= 3){
        cart->mbc = 1;
    } else if(cart->mem[MBC] >= 5 && cart->mem[MBC] <= 6){
        cart->mbc = 2;
    } else {
        // invalid mbc flag
        return false;
    }

    // read rambank info
    cart->ramCount = cart->mem[NRB];
    if(cart->ramCount < 0 || cart->ramCount > 4)
        return false;
    memset(cart->ram, 0, sizeof(cart->ram));
    cart->ramIdx = 0;

    cart->romIdx = 1;
    cart->useRam = false;
    cart->useRombank = false;
    return true;
}
