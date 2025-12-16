#ifndef BLOCKER_HPP
#define BLOCKER_HPP

#include <SDL_rect.h>

class Renderer; // custom Renderer

class Blocker
{
public:
    Blocker(int x, int y);
    ~Blocker();

    void update();
    void render(Renderer& renderer);

    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    SDL_Rect rect;
    int width;
    int height;

};

#endif // BLOCKER_HPP