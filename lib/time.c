#include "../headers/time.h"

gametime_t time = {0};

#if defined(_WIN64) || defined(_WIN32) || defined(__CYGWIN__)

#include <windows.h>
long date_now()
{
    SYSTEMTIME time;
    GetSystemTime(&time);
    return (time.wSecond * 1000) + time.wMilliseconds;
}

#else

/* TODO - unix style time proc here */
#include <windows.h>
long date_now()
{
    SYSTEMTIME time;
    GetSystemTime(&time);
    return (time.wSecond * 1000) + time.wMilliseconds;
}

#endif

void rewind_clock()
{
    time.elapsed_ms = 0;
    time.delta_ms = 0;
    time.then_ms = date_now();
}

void tick()
{
    const long now = date_now();
    time.delta_ms = now - time.then_ms;
    time.elapsed_ms += time.delta_ms;
    time.then_ms = now;
    time.delta = time.delta_ms * 0.001;
    time.elapsed = time.elapsed_ms * 0.001;
}
