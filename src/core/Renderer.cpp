#include "core/Renderer.hpp"

#include "helpers/Circle.hpp"
#include "ui/Font.hpp"

#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>

Renderer::Renderer(SDL_Window *window)
{
    SDL_Renderer *raw_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!raw_renderer)
    {
        std::cerr << "Error during renderer initialization, SDL_GetError:"
                  << SDL_GetError() << std::endl;
        return;
    }

    m_renderer.reset(raw_renderer, SDL_DestroyRenderer);
}

Renderer::~Renderer() = default;

void Renderer::beginFrame()
{
    SDL_SetRenderDrawColor(m_renderer.get(),
                           BACKGROUND_COLOR.r,
                           BACKGROUND_COLOR.g,
                           BACKGROUND_COLOR.b,
                           BACKGROUND_COLOR.a);
    SDL_RenderClear(m_renderer.get());
}

void Renderer::setDrawColor(const SDL_Color &c)
{
    SDL_SetRenderDrawColor(m_renderer.get(), c.r, c.g, c.b, c.a);
}

void Renderer::drawTexture(SDL_Texture *texture, int x, int y)
{
    if (!texture)
        return;
    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    SDL_Rect dst{x, y, w, h};
    SDL_RenderCopy(m_renderer.get(), texture, nullptr, &dst);
}

void Renderer::drawRect(const SDL_Rect &rect)
{
    SDL_RenderFillRect(m_renderer.get(), &rect);
}

void Renderer::drawCircle(const Circle &circle)
{
    for (int x = -circle.radius; x <= circle.radius; x++)
    {
        for (int y = -circle.radius; y <= circle.radius; y++)
        {
            if (x * x + y * y <= circle.radius * circle.radius)
            {
                SDL_RenderDrawPoint(m_renderer.get(), circle.x + x, circle.y + y);
            }
        }
    }
}

void Renderer::drawText(const Font &font, const std::string &text, int x, int y, SDL_Color color)
{
    if (!font.getSDLFont())
        return;

    SDL_Surface *surface = TTF_RenderText_Solid(font.getSDLFont(), text.c_str(), color);
    if (!surface)
        return;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer.get(), surface);
    SDL_FreeSurface(surface);

    if (texture)
    {
        int w, h;
        SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
        SDL_Rect dst{x, y, w, h};
        SDL_RenderCopy(m_renderer.get(), texture, nullptr, &dst);
        SDL_DestroyTexture(texture);
    }
}

void Renderer::endFrame()
{
    SDL_RenderPresent(m_renderer.get());
}