#pragma once
#include <SDL2/SDL.h>

class Timer {
private:
    Uint32 startTime_;
public:
    Timer();

    /**
     * Sets the timer's start time to the current game tick.
    */
    void reset();

    /**
     * Gives user the elapsed time since the Timer reset.
     * 
     * \return the amount of time in ms since the Timer was reset
    */
    Uint32 elapsedTime();
};