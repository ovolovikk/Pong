#pragma once

#include <string>
#include <memory>

#include <SDL_ttf.h>

class Renderer;

class Font
{
public:
    Font(const std::string &path, int size);
    ~Font();

    SDL_Texture *renderText(SDL_Renderer *renderer, const std::string &text, SDL_Color color) const;

private:
    std::shared_ptr<TTF_Font> m_font;

    friend class Renderer;
};
