#include "core/Window.hpp"

#include <iostream>

#include <SDL.h>

Window::Window(const std::string_view &title, int width, int height)
    : m_width(width), m_height(height), m_window(nullptr)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Error during SDL2 initialization, SDLGetError: "
                  << SDL_GetError() << std::endl;
        return;
    }

    m_window = SDL_CreateWindow(title.data(),
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              m_width, m_height, 0);
    if (!m_window)
    {
        std::cerr << "Error during window initialization, SDL_GerError: "
                  << SDL_GetError() << std::endl;
        return;
    }
}

Window::~Window()
{
    if (m_window)
    {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}
