#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <assert.h>

#include "headers/events.h"
#include "headers/graphics.h"
#include "headers/main.h"
#include "headers/net.h"
#include "headers/time.h"
#include "headers/utils.h"

#define TARGET_FPS 10.0

const double desired_delta = 1.0/TARGET_FPS;

void draw()
{
    //SDL_SetRenderDrawColor(renderer, 255, 0, 128, 255);
    //SDL_RenderClear(renderer);
    SDL_FillRect(screen, NULL, 0x0088FFFF);

    // custom drawing
    SDL_Rect dstrect = {
        .x = time.elapsed_ms % 1000,
        .y = 0,
        .h = 100,
        .w = 100,
    };
    SDL_BlitScaled(img, NULL, screen, &dstrect);
    //SDL_BlitSurface(img, NULL, screen, &dstrect);

    SDL_UpdateWindowSurface(window);
    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[])
{

    init_graphics();
    init_net();

    register_custom_events();

    rewind_clock();

    bool running = true;
    double since_last_frame = 0.0;
    while (running) {
        running = proc_evts();
        if (since_last_frame >= desired_delta) {
            draw();
            since_last_frame = 0;
        }
        since_last_frame += time.delta;
        tick();
    }

    quit_net();
    quit_graphics();
    return 0;

}
