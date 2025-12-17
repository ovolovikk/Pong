#ifndef RENDERER_HPP
#define RENDERER_HPP

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
    Renderer(SDL_Window* window);
    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    void drawText(const std::string& text, int x, int y, int size, SDL_Color color);

    void beginFrame();
    void draw();
    void drawRect(const SDL_Rect& rect);
    void drawCircle(const Circle& circle, const SDL_Color& color);
    void endFrame();

    auto getSDLRenderer() const { return renderer; }

private:
    SDL_Renderer* renderer;
    TTF_Font* font = nullptr;
    
};

#endif // RENDERER_HPP
