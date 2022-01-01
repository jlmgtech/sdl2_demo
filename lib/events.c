#include <SDL2/SDL.h>
#include <stdbool.h>
#include <assert.h>

uint32_t EVT_DRAW;
uint32_t EVT_WAIT;

bool proc_evts()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return false;
            case SDL_KEYDOWN:
                return event.key.keysym.sym != SDLK_ESCAPE;
        }
    }

    return true;
}

void register_custom_events()
{
    EVT_DRAW = SDL_RegisterEvents(1);
    assert(EVT_DRAW != -1);
}
