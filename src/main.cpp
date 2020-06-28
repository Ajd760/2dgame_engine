#include <iostream>
#include "./Constants.h"
#include "./Game.h"

int main(int argc, char* args[])
{
    Game* game = new Game();
    game->init(WINDOW_WIDTH, WINDOW_HEIGHT);

    std::cout << "This Visual Studio thing is dumb" << std::endl;

    while(game->isRunning())
    {
        //run game
        
    }

    return 0;
}