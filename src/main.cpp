#include "core/Game.hpp"

#include <iostream>

int main()
{
    Game game("Pong", 1280, 960);
    if (!game.isValid())
    {
        return -1;
    }

    game.run();
    return 0;
}