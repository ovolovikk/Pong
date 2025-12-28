#include "core/Renderer.hpp"

#include "helpers/Circle.hpp"

#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>

Renderer::Renderer(SDL_Window *window_)
{
    m_renderer = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (!m_renderer)
    {
        std::cerr << "Error during renderer initialization, SDL_GetError:"
                  << SDL_GetError() << std::endl;
        return;
    }
}

Renderer::~Renderer()
{
    if (m_renderer)
    {
        SDL_DestroyRenderer(m_renderer);
    }
}

void Renderer::beginFrame()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
}

void Renderer::drawRect(const SDL_Rect &rect)
{
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer, &rect);
}

void Renderer::drawCircle(const Circle &circle, const SDL_Color &color)
{
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);

    for (int x = -circle.radius; x <= circle.radius; x++)
    {
        for (int y = -circle.radius; y <= circle.radius; y++)
        {
            if (x * x + y * y <= circle.radius * circle.radius)
            {
                SDL_RenderDrawPoint(m_renderer, circle.x + x, circle.y + y);
            }
        }
    }
}

void Renderer::drawText(const std::string& text, int x, int y, 
                        int size, SDL_Color color)
{
    TTF_Font* font = TTF_OpenFont("assets/font.ttf", size);
    if (!font)
    {
        SDL_Log("TTF_OpenFont failed: %s", TTF_GetError());
        return;
    }

    SDL_Surface* surface =
        TTF_RenderText_Solid(font, text.c_str(), color);

    if (!surface)
    {
        TTF_CloseFont(font);
        return;
    }

    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(m_renderer, surface);

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

    if (!texture)
        return;

    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);

    SDL_Rect dst{ x, y, w, h };
    SDL_RenderCopy(m_renderer, texture, nullptr, &dst);

    SDL_DestroyTexture(texture);
}

void Renderer::endFrame()
{
    SDL_RenderPresent(m_renderer);
}