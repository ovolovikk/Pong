#include "core/Game.hpp"

#include <iostream>

int main()
{
    static constexpr std::string_view TITLE = "Pong";
    static constexpr auto WIDTH = 320 * 4, HEIGHT = 320 * 3;

    std::cout << TITLE << std::endl;

    Game game(TITLE, WIDTH, HEIGHT);
    return 0;
}