#ifndef time_h
#define time_h

typedef struct {
    long elapsed_ms;
    long delta_ms;
    long then_ms;
    double delta;
    double elapsed;
} gametime_t;

extern gametime_t time;
long date_now();
void rewind_clock();
void tick();

#endif
