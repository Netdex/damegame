//
// Created by netdex on 7/4/2018.
//


#include <stdio.h>
#include "sdl_wrapper.h"

SDL_Window* SDLWindow = NULL;
SDL_Surface* SDLSurface = NULL;
SDL_Renderer* SDLRenderer = NULL;

bool CSDL_Init(const char *title, int width, int height){
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    SDLWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                 width, height, SDL_WINDOW_SHOWN);
    if (SDLWindow == NULL)
    {
        printf("SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    SDLSurface = SDL_GetWindowSurface(SDLWindow);
    if (SDLSurface == NULL)
    {
        printf("SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    SDLRenderer = SDL_CreateRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (SDLRenderer == NULL)
    {
        printf("SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

void CSDL_Destroy()
{
    SDL_DestroyRenderer(SDLRenderer);
    SDL_FreeSurface(SDLSurface);
    SDL_DestroyWindow(SDLWindow);
    SDL_Quit();
}