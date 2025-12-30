#pragma once

#include "helpers/Colors.hpp"

#include <string>
#include <memory>

#include <SDL.h>

struct Circle;
struct TTF_Font;
class Font; // my Font

class Renderer
{
public:
    Renderer(SDL_Window *window);
    ~Renderer();

    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    void beginFrame();

    void setDrawColor(const SDL_Color &color);

    void drawTexture(SDL_Texture *texture, int x, int y);
    void drawRect(const SDL_Rect &rect);
    void drawCircle(const Circle &circle);
    void drawText(const Font &font, const std::string &text, int x, int y, SDL_Color color);
    void endFrame();

    SDL_Renderer *getSDLRenderer() const { return m_renderer.get(); }

private:
    std::shared_ptr<SDL_Renderer> m_renderer = nullptr;

    static constexpr SDL_Color BACKGROUND_COLOR = Colors::Black;
};
