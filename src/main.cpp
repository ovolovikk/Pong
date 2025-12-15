#include "core/Game.hpp"

#include <iostream>

int main()
{
    constexpr std::string_view TITLE = "Pong";
    constexpr auto WIDTH = 320 * 4, HEIGHT = 320 * 3;

    std::cout << TITLE << std::endl;

    Game game(TITLE, 1280, 960);
    return 0;
}