#pragma once

#include "helpers/Colors.hpp"

#include <SDL_rect.h>

class Renderer;

class GameObject
{
public:
    GameObject() = default;
    virtual ~GameObject() = default;

    virtual void update() = 0;
    virtual void render(Renderer &renderer) = 0;

    void setColor(const SDL_Color &color) { m_color = color; }

protected:
    float m_x = 0.f, m_y = 0.f;
    int m_w = 0, m_h = 0;
    SDL_Color m_color = Colors::White;
};
