#pragma once

#include "core/GameObject.hpp"

#include <SDL_rect.h>

class Renderer; // custom Renderer

class Blocker : public GameObject
{
public:
    Blocker(int x, int y, int windowHeight);
    ~Blocker() override;

    void update() override;
    void render(Renderer &renderer) override;

    void setDirection(int direction) { m_direction = direction; }

    int getWidth() const { return m_w; }
    int getHeight() const { return m_h; }
    int getY() const { return m_rect.y; }
    const SDL_Rect &getRect() const { return m_rect; };

private:
    constexpr static int SPEED = 10;
    constexpr static int HEIGHT = 100;
    constexpr static int WIDTH = 20;

    SDL_Rect m_rect;
    int m_windowHeight;
    int m_direction = 0;
};
