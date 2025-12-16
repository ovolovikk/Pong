#ifndef BALL_HPP
#define BALL_HPP

#include "helpers/Circle.hpp"

struct SDL_Color;

class Ball
{
public:
    Ball(const Circle& p, SDL_Color color);
    ~Ball();

    void update();
    void render(Renderer& renderer);

private:
    Circle circle;
};

#endif //BALL_HPP