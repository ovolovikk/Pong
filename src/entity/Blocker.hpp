#ifndef BLOCKER_HPP
#define BLOCKER_HPP

#include <SDL_rect.h>

class Renderer; // custom Renderer

class Blocker
{
public:
    Blocker(int x, int y, int windowHeight);
    ~Blocker();

    void update();
    void render(Renderer &renderer);
    void setDirection(int direction_) { direction = direction_; }

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getY() const { return rect.y; }
    const SDL_Rect &getRect() const { return rect; }

private:
    constexpr static int SPEED = 5;

    SDL_Rect rect;
    int width;
    int height;
    int windowHeight;
    int direction;
};

#endif // BLOCKER_HPP