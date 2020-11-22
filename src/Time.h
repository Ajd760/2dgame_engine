#ifndef TIME_H
#define TIME_H

#include <SDL2/SDL.h>

class Time {
    public:
        Time();
        ~Time();
        float GetDeltaTime() const;
        int GetLastFrameTicks() const;
        void UpdateDeltaTime();
        void ClampDeltaTime();
        void UpdateLastFrameTicks();
        void CalcAndExecFrameDelay();

    private:
        int lastFrameTicks;
        float deltaTime;


};


#endif