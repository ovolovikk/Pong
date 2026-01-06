#pragma once

#include "helpers/Circle.hpp"
#include "core/GameObject.hpp"

#include <SDL.h>

class Renderer;

class Ball : public GameObject
{
public:
    Ball(const Circle &c, int windowWidth, int windowHeight);
    ~Ball() override;

    void update() override;
    void render(Renderer &renderer) override;

    void reset();
    void checkCollision(const SDL_Rect &rect);

    Circle getCircle() const;
    auto getX() const;

private:
    int m_windowWidth = 0;
    int m_windowHeight = 0;
    float m_dx = 4.f;
    float m_dy = 4.f;
    float m_speed = 4.f;
};
