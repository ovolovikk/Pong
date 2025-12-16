#ifndef RENDERER_HPP
#define RENDERER_HPP

struct SDL_Renderer;
struct SDL_Window;
struct SDL_Rect;

class Renderer
{
public:
    Renderer(SDL_Window* window);
    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    void init();

    void beginFrame();
    void draw();
    void drawRect(const SDL_Rect& rect);
    void endFrame();

    auto getSDLRenderer() const { return renderer; }

private:
    SDL_Renderer* renderer;
    
};

#endif // RENDERER_HPP
