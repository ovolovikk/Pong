#pragma once

#include <string>

#include <SDL_ttf.h>

class Font
{
public:
    Font(const std::string& path, int size);
    ~Font();

    SDL_Texture* renderText(SDL_Renderer* renderer,
                            const std::string& text,
                            SDL_Color color) const;

private:
    TTF_Font* m_font = nullptr;
};
