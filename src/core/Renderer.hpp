#pragma once

#include "helpers/Colors.hpp"

#include <string>
#include <memory>

#include <SDL.h>

struct TTF_Font;
class Font;
class Score;
class Window;

class Renderer
{
public:
    Renderer(const Window& window);
    ~Renderer();

    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    void beginFrame();

    void setDrawColor(const SDL_Color &color);

    void drawTexture(SDL_Texture *texture, int x, int y);
    void drawRect(const SDL_Rect &rect);
    void drawCircle(int x, int y, int radius);
    void drawText(const Font &font, const std::string &text, int x, int y, SDL_Color color);
    void endFrame();
private:
    std::shared_ptr<SDL_Renderer> m_renderer;

    static constexpr SDL_Color BACKGROUND_COLOR = Colors::Black;
    
    friend class Score;
};
