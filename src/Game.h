#ifndef _Game.h
#define _Game.h

class Game
{
    public:
        Game();
        void init(unsigned int windowWidth, unsigned int windowHeight);
    private:
        unsigned int window_width;
        unsigned int window_height;
};

#endif