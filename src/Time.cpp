#include ".\Time.h"
#include ".\Constants.h"

Time::Time()
{
    lastFrameTicks = SDL_GetTicks();
}

Time::~Time()
{}

float Time::getDeltaTime() const
{
    return deltaTime;
}
int Time::getLastFrameTicks() const
{
    return lastFrameTicks;
}

void Time::updateDeltaTime()
{
    deltaTime = (SDL_GetTicks() - lastFrameTicks) / 1000.0f;
}

void Time::clampDeltaTime()
{
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;
}

void Time::updateLastFrameTicks()
{
    lastFrameTicks = SDL_GetTicks();
}

void Time::calcAndExecFrameDelay()
{
    int delayTime = TARGET_FRAME_TIME - (SDL_GetTicks() - lastFrameTicks);

    if(delayTime > 0 && delayTime <= TARGET_FRAME_TIME)
    {
        SDL_Delay(delayTime);
    }   
}