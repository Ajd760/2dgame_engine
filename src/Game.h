#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include ".\Time.h"

class Game
{
    public:
        Game();
        ~Game();
        void init(unsigned int winWidth, unsigned int winHeight);
        bool isRunning() const;
        void processInput();
        void update();
        void render();
        void cleanup(); // On game close

        Time* timer;
        int lastFrameTicks;
        

    private:
        unsigned int window_width;
        unsigned int window_height;
        bool bisRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;

};

#endif