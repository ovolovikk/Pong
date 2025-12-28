#pragma once

#include <string>

struct SDL_Renderer;
struct SDL_Window;
struct SDL_Rect;
struct SDL_Color;
struct Circle;
struct TTF_Font;

class Renderer
{
public:
    Renderer(SDL_Window *window);
    ~Renderer();

    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    void beginFrame();
    void drawRect(const SDL_Rect &rect);
    void drawCircle(const Circle &circle, const SDL_Color &color);
    void drawText(const std::string& text, int x, int y, 
                  int size, SDL_Color color);
    void endFrame();

private:
    SDL_Renderer *m_renderer = nullptr;
};
