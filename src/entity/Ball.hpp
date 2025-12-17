#ifndef BALL_HPP
#define BALL_HPP

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

    const Circle &getCircle() const { return circle; }
    auto getX() const { return circle.x; }

private:
    Circle circle;
    SDL_Color color;
    int windowWidth;
    int windowHeight;
    float dx;
    float dy;
    float speed;

    // Helper to keep track of precise position
    float x_pos;
    float y_pos;
};

#endif // BALL_HPP