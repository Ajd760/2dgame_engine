#include <iostream>
#include "Constants.h"
#include "Game.h"

Game::Game()
{
    bisRunning = false;
}

void Game::init(unsigned int winWidth, unsigned int winHeight)
{
    window_width = winWidth;
    window_height = winHeight;
    
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error: SDL_Init Failed" << std::endl;
        return;
    }

    window = SDL_CreateWindow("2dGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_SHOWN);
    if(!window)
    {
        std::cerr << "Error: SDL_CreateWindow Failed" << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer)
    {
        std::cerr << "Error: SDL_CreateRenderer Failed" << std::endl;
        return;
    }

    bisRunning = true;
}

bool Game::isRunning() const
{
    return bisRunning;
}

//temp stuff /////////////////////////////////////////
float projectilePosX = 0.0f;
float projectilePosY = 0.0f;
const float projectileVelX = 0.3f;
const float projectileVelY = 0.3f;
//////////////////////////////////////////////////////


void Game::processInput()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT: 
            {   
                bisRunning = false;
                break;
            }
            case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    bisRunning = false;
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

void Game::update()
{
    projectilePosX += projectileVelX;
    projectilePosY += projectileVelY;
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
    SDL_RenderClear(renderer); //clear the current rendering target with the clear color
    
    SDL_Rect projectile 
    {
        (int)projectilePosX, 
        (int)projectilePosY,
        10, 
        10
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &projectile);

    SDL_RenderPresent(renderer); // swap buffers
}

void Game::cleanup()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}