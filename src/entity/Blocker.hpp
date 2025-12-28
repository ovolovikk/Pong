#pragma once

#include <SDL_rect.h>

class Renderer; // custom Renderer

class Blocker
{
public:
    Blocker(int x, int y, int windowHeight);
    ~Blocker();

    void update();
    void render(Renderer &renderer);
    void setDirection(int direction_) { m_direction = direction_; }

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    int getY() const { return m_rect.y; }
    const SDL_Rect &getRect() const { return m_rect; }

private:
    constexpr static int SPEED = 10;

    SDL_Rect m_rect;
    int m_width;
    int m_height;
    int m_windowHeight;
    int m_direction;
};
