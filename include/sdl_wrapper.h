//
// Created by netdex on 7/4/2018.
//

#ifndef DAMEGAME_SDL_WRAPPER_H
#define DAMEGAME_SDL_WRAPPER_H

#include <SDL.h>
#include <stdbool.h>

extern SDL_Window* SDLWindow;
extern SDL_Surface* SDLSurface;
extern SDL_Renderer* SDLRenderer;

bool CSDL_Init(const char *title, int width, int height);
void CSDL_Destroy();

#endif //DAMEGAME_SDL_WRAPPER_H
