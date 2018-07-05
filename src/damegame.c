
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <cpuinst.h>

#include "sdl_wrapper.h"
#include "cpuinst.h"
#include "gbcpu.h"
#include "cputable.h"

int main(int argc, char *argv[]){
    if (!CSDL_Init("damegame", 256, 256))
        return -1;

    gb_init();

    cpuinst *inst;

    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if(e.type == SDL_KEYUP){
                switch(e.key.keysym.sym){
                    case SDLK_RETURN:
                        inst = gb_step();
                        gb_printreg();
                        printf("-------------------------------------------------------------------------\n");
                        break;
                    default:
                        break;
                }
            }
        }
        SDL_SetRenderDrawColor(SDLRenderer, 0, 0, 0, 0xFF);
        SDL_RenderClear(SDLRenderer);
        SDL_RenderPresent(SDLRenderer);
    }

    CSDL_Destroy();
    return 0;
}
