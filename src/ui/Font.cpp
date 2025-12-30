#include "ui/Font.hpp"

#include <iostream>

Font::Font(const std::string &path, int size)
{
    TTF_Font *raw_font = TTF_OpenFont(path.c_str(), size);
    if (!raw_font)
    {
        std::cerr << "Error during Font initialization: " << TTF_GetError() << std::endl;
    }

    m_font.reset(raw_font, TTF_CloseFont);
}

Font::~Font() = default;

SDL_Texture *Font::renderText(SDL_Renderer *renderer, const std::string &text, SDL_Color color) const
{
    SDL_Surface *surface = TTF_RenderText_Solid(m_font.get(), text.c_str(), color);
    if (!surface)
        return nullptr;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}