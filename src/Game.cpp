#include <iostream>
#include ".\Constants.h"
#include ".\components\TransformComponent.h"
#include ".\Game.h"
#include "..\lib\glm\glm.hpp"

EntityManager manager;
SDL_Renderer* Game::renderer;

Game::Game() {
    bisRunning = false;
    timer = new Time();
}

Game::~Game() {

}

// Initialize all SDL subsystems, get window, renderer etc
void Game::Init(unsigned int winWidth, unsigned int winHeight) {
    window_width = winWidth;
    window_height = winHeight;
    
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error: SDL_Init Failed" << std::endl;
        return;
    }

    window = SDL_CreateWindow("2dGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_SHOWN);
    if(!window) {
        std::cerr << "Error: SDL_CreateWindow Failed" << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer) {
        std::cerr << "Error: SDL_CreateRenderer Failed" << std::endl;
        return;
    }

    // temp
    LoadLevel(0);

    bisRunning = true;
}

void Game::LoadLevel(int levelNum) {
    // temp
    Entity& firstEntity(manager.AddEntity("leftProjectile"));
    firstEntity.addComponent<TransformComponent>(0, 0, 20, 20, 24, 24, 1);

    Entity& secondEntity(manager.AddEntity("rightProjectile"));
    secondEntity.addComponent<TransformComponent>((WINDOW_WIDTH - 24), 0, -20, 20, 24, 24, 1);

    Entity& thirdEntity(manager.AddEntity("rightProjectile"));
    thirdEntity.addComponent<TransformComponent>(0, (WINDOW_HEIGHT - 24), 20, -20, 24, 24, 1);

    Entity& fourthEntity(manager.AddEntity("rightProjectile"));
    fourthEntity.addComponent<TransformComponent>((WINDOW_WIDTH - 24), (WINDOW_HEIGHT - 24), -20, -20, 24, 24, 1);

    manager.ListEntities();

}

bool Game::IsRunning() const {
    return bisRunning;
}

void Game::ProcessInput() {
    SDL_Event event;
    if(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT: {   
                bisRunning = false;
                break;
            }
            case SDL_KEYDOWN: {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    bisRunning = false;
                }
                break;
            }
            default: {
                break;
            }
        }
    }
}

void Game::Update() {
    //Wait until target frame time has elapsed since last frame, if necessary
    timer->calcAndExecFrameDelay();

    //Timer-update
    timer->updateDeltaTime();
    timer->clampDeltaTime();
    timer->updateLastFrameTicks();

    manager.Update(timer->getDeltaTime());
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
    SDL_RenderClear(renderer); //clear the current rendering target with the clear color

    if(manager.IsEmpty()) {
        std::cerr << "Nothing in Entity Manager" << std::endl;
        return;
    }

    manager.Render();

    SDL_RenderPresent(renderer); // swap buffers
}

void Game::Cleanup() {
    timer = NULL;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}