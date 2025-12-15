#ifndef RENDERER_HPP
#define RENDERER_HPP

class SDL_Renderer;
class SDL_Window;

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
    void endFrame();

    auto getSDLRenderer() const { return renderer; }

private:
    SDL_Renderer* renderer;
    
};

#endif // RENDERER_HPP
