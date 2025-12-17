#include "core/Window.hpp"

#include <iostream>

#include <SDL.h>

Window::Window(const std::string_view &title_, int width_, int height_)
    : width(width_), height(height_), window(nullptr)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Error during SDL2 initialization, SDLGetError: "
                  << SDL_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow(title_.data(),
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height, 0);
    if (!window)
    {
        std::cerr << "Error during window initialization, SDL_GerError: "
                  << SDL_GetError() << std::endl;
        return;
    }
}

Window::~Window()
{
    if (window)
    {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}
