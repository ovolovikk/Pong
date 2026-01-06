#pragma once

#include "core/GameObject.hpp"

#include <SDL.h>

class Renderer; // custom Renderer

class Blocker : public GameObject
{
public:
    Blocker(int x, int y, int windowHeight);
    ~Blocker() override;

    void update() override;
    void render(Renderer &renderer) override;

    void setDirection(int direction);

    int getHeight() const;
    int getY() const;
    const SDL_Rect &getRect() const;

private:
    SDL_Rect m_rect;
    int m_windowHeight = 0;
    int m_direction = 0;
};
