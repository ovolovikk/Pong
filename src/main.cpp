#include <SDL.h>

#include <iostream>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    std::cout << "Pong!" << std::endl;

    return 0;
}