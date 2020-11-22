#include <iostream>
#include "./Constants.h"
#include "./Game.h"

int main(int argc, char* args[]) {
    Game* game = new Game();
    game->Init(WINDOW_WIDTH, WINDOW_HEIGHT);

    std::cout << "S7yl3-ch3ck" << std::endl;

    SDL_GetTicks();

    while(game->IsRunning()) {
        //run game
        game->ProcessInput();
        game->Update();
        game->Render();
    }

    game->Cleanup();
    return 0;
}