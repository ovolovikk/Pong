#include "ui/Font.hpp"

#include <iostream>

Font::Font(const std::string& path, int size)
{
    m_font = TTF_OpenFont(path.c_str(), size);
    if (!m_font)
    {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
}

Font::~Font()
{
    if (m_font)
        TTF_CloseFont(m_font);
}

SDL_Texture* Font::renderText(SDL_Renderer* renderer,
                              const std::string& text,
                              SDL_Color color) const
{
    SDL_Surface* surface = TTF_RenderText_Solid(m_font, text.c_str(), color);
    if (!surface)
        return nullptr;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
