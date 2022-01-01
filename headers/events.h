#ifndef events_h
#define events_h

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>

extern uint32_t EVT_DRAW;
extern uint32_t EVT_WAIT;

bool proc_evts();
void register_custom_events();

#endif
