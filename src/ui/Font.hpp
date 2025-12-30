#pragma once

#include <string>
#include <memory>

#include <SDL_ttf.h>

class Font
{
public:
    Font(const std::string &path, int size);
    ~Font();

    TTF_Font *getSDLFont() const { return m_font.get(); }

    SDL_Texture *renderText(SDL_Renderer *renderer, const std::string &text, SDL_Color color) const;

private:
    std::shared_ptr<TTF_Font> m_font = nullptr;
};
