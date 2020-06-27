#include <iostream>
#include "./Constants.h"
#include "./Game.h"

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

    window = SDL_CreateWindow("2dGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_BORDERLESS);
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

void Game::processInput()
{

}

void Game::update()
{

}

void Game::render()
{

}

void Game::cleanup()
{

}