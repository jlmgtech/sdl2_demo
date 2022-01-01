#ifndef graphics_h
#define graphics_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void init_graphics();
SDL_Surface* loadSurface(const char *restrict const path);
void quit_graphics();

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Surface *screen;
extern SDL_Surface *img;

#endif
