#include "../headers/main.h"
#include "../headers/graphics.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *img = NULL;

void init_graphics()
{
    assert(SDL_Init(SDL_INIT_EVERYTHING) >= 0);
    window = SDL_CreateWindow(
            "Hello, World!",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            WIDTH,
            HEIGHT,
            SDL_WINDOW_ALLOW_HIGHDPI);

    assert(window);
    screen = SDL_GetWindowSurface(window);

    //renderer = SDL_CreateRenderer(window, -1, 0);
    //assert(renderer);

    // INIT SDL IMG
    const int imgFlags = IMG_INIT_PNG;
    const bool img_init_success = IMG_Init(imgFlags) & imgFlags;
    assert(img_init_success);

    // LOAD IMAGE
    const char *const imgname = "preview.png";
    img = loadSurface(imgname);
    assert(img);
}

SDL_Surface* loadSurface(const char *restrict const path)
{
    SDL_Surface *output = NULL;
    SDL_Surface *surf = IMG_Load(path);
    assert(surf);

    // if you ever figure this out, lemme know
    // this should be screen_surface->format, but we're using renderer which
    // should not be combined with the SDL_GetWindowSurface API.
    output = SDL_ConvertSurface(surf, screen->format, 0);
    assert(output);

    SDL_FreeSurface(surf);
    return output;
}

void quit_graphics()
{
    SDL_FreeSurface(img);
    img = NULL;

    SDL_DestroyWindow(window);
    SDL_Quit();
}
