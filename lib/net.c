#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include <assert.h>
#include "../headers/net.h"

void init_net()
{
    assert(SDLNet_Init() != -1);
}

void quit_net()
{
    SDLNet_Quit();
}
