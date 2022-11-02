#include <Timer.h>

Timer::Timer() {
    startTime_ = SDL_GetTicks();
}

void Timer::reset() {
    startTime_ = SDL_GetTicks();
}

Uint32 Timer::elapsedTime() {
    return SDL_GetTicks() - startTime_;
}