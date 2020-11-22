#include ".\Time.h"
#include ".\Constants.h"

Time::Time() {
    lastFrameTicks = SDL_GetTicks();
}

Time::~Time() { }

float Time::GetDeltaTime() const {
    return deltaTime;
}

int Time::GetLastFrameTicks() const{
    return lastFrameTicks;
}

// Calc deltaTime = time between cycles in ms, converted to seconds 
void Time::UpdateDeltaTime() {
    deltaTime = (SDL_GetTicks() - lastFrameTicks) / 1000.0f;
}

// Clamp delta time to prevent lag or pause from making time warp fast forward
void Time::ClampDeltaTime() {
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;
}

// Call every udpate(), keeps track of time at last update
void Time::UpdateLastFrameTicks() {
    lastFrameTicks = SDL_GetTicks();
}

void Time::CalcAndExecFrameDelay() {
    // Calc delayTime in ms as desired frame window minus delta time between cycles in ms
    int delayTime = TARGET_FRAME_TIME - (SDL_GetTicks() - lastFrameTicks);

    // If calc'd delay is > 0 and <= than desired frame window, delay frame swap by delayTime
    if(delayTime > 0 && delayTime <= TARGET_FRAME_TIME) {
        SDL_Delay(delayTime);
    }   
}