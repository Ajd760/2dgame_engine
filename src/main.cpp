#include <iostream>
#include "./Constants.h"
#include "./Game.h"

int main(int argc, char* args[])
{
    Game* game = new Game();
    game->init(WINDOW_WIDTH, WINDOW_HEIGHT);

    while(game->isRunning())
    {
        //run game
    }

    return 0;
}