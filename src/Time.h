#ifndef TIME_H
#define TIME_H

#include <SDL2/SDL.h>

class Time {
    public:
        Time();
        ~Time();
        float getDeltaTime() const;
        int getLastFrameTicks() const;
        void updateDeltaTime();
        void clampDeltaTime();
        void updateLastFrameTicks();
        void calcAndExecFrameDelay();

    private:
        int lastFrameTicks;
        float deltaTime;


};


#endif