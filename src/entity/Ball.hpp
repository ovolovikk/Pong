#pragma once

#include "helpers/Circle.hpp"

#include <SDL.h>

class Renderer;

class Ball
{
public:
    Ball(const Circle &p, SDL_Color color, int windowWidth, int windowHeight);
    ~Ball();

    void update();
    void reset();
    void render(Renderer &renderer);
    void checkCollision(const SDL_Rect &rect);

    const Circle &getCircle() const { return m_circle; }
    auto getX() const { return m_circle.x; }

private:
    Circle m_circle;
    SDL_Color m_color;
    int m_windowWidth;
    int m_windowHeight;
    float m_dx;
    float m_dy;
    float m_speed;

    // Helper to keep track of precise position
    float m_x_pos;
    float m_y_pos;
};
