#include "core/Renderer.hpp"

#include <iostream>

#include <SDL.h>

Renderer::Renderer(SDL_Window* window_)
{
    renderer = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer)
    {
        std::cerr << "Error during renderer initialization, SDL_GetError:"
                  << SDL_GetError() << std::endl;
        return;
    }
}

Renderer::~Renderer()
{
    if(renderer) {
        SDL_DestroyRenderer(renderer);
    }
}

void Renderer::beginFrame()
{
    SDL_RenderClear(renderer);
}

void Renderer::draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 100, 255);
}

void Renderer::endFrame()
{
    SDL_RenderPresent(renderer);
}