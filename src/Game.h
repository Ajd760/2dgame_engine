#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include ".\Time.h"
#include ".\EntityManager.h"

class Game {
    public:
        Game();
        ~Game();
        void Init(unsigned int winWidth, unsigned int winHeight);
        bool IsRunning() const;
        void ProcessInput();
        void Update();
        void Render();
        void LoadLevel(int levelNum);
        void Cleanup(); // On game close

        Time* timer;
        int lastFrameTicks;
        static SDL_Renderer* renderer;

    private:
        unsigned int window_width;
        unsigned int window_height;
        bool bisRunning;
        SDL_Window* window;
};

#endif