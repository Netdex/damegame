
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <cpuinst.h>
#include "gbcpu.h"

#include "cputable.h"

int main(const int argc, const char *argv[]){
	gb_init();
	gb_reset();

    cpuinst *inst;
    for(;;){
        inst = gb_step();
        gb_printreg();
        getchar();
    }
}
