#include <iostream>
#include <SDL2/SDL.h>
#include "./Constants.h"
#include "./Game.h"

int main(int argc, char* args[])
{
    Game* game = new Game();
    game->init(WINDOW_WIDTH, WINDOW_HEIGHT);

    return 0;
}