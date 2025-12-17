#include "core/Renderer.hpp"

#include "helpers/Circle.hpp"

#include <iostream>
#include <cmath>

#include <SDL.h>
#include <SDL_ttf.h>

Renderer::Renderer(SDL_Window *window_)
{
    renderer = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Error during renderer initialization, SDL_GetError:"
                  << SDL_GetError() << std::endl;
        return;
    }

    if (TTF_Init() == -1)
    {
        std::cerr << "error during TTF initialization, TTF_GetError: "
                  << TTF_GetError() << std::endl;
    }
}

Renderer::~Renderer()
{
    if (font)
    {
        TTF_CloseFont(font);
        TTF_Quit();
    }
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
}

void Renderer::drawText(const std::string &text, int x, int y, int size, SDL_Color color)
{
    if (!font)
    {
        font = TTF_OpenFont("assets/font.ttf", size);
    }

    if (!font)
    {
        return;
    }

    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);

    if (surface)
    {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect dst = {x, y, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, NULL, &dst);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}

void Renderer::beginFrame()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Renderer::draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 100, 255);
}

void Renderer::drawRect(const SDL_Rect &rect)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Renderer::drawCircle(const Circle &circle, const SDL_Color &color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    for (int x = -circle.radius; x <= circle.radius; x++)
    {
        for (int y = -circle.radius; y <= circle.radius; y++)
        {
            if (x * x + y * y <= circle.radius * circle.radius)
            {
                SDL_RenderDrawPoint(renderer, circle.x + x, circle.y + y);
            }
        }
    }
}

void Renderer::endFrame()
{
    SDL_RenderPresent(renderer);
}