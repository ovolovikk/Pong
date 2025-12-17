#include "Ball.hpp"
#include "core/Renderer.hpp"

#include <SDL.h>
#include <cmath>
#include <algorithm>

Ball::Ball(const Circle& p, SDL_Color color, int windowWidth, int windowHeight)
    : circle(p), color(color), 
    windowWidth(windowWidth), windowHeight(windowHeight),
    dx(4), dy(4)
{

}

Ball::~Ball() = default;

void Ball::update()
{
    circle.x += dx;
    circle.y += dy;

    if (circle.y - circle.radius < 0) {
        circle.y = circle.radius;
        dy = -dy;
    }
    if (circle.y + circle.radius > windowHeight) {
        circle.y = windowHeight - circle.radius;
        dy = -dy;
    }
}

void Ball::reset()
{
    circle.x = windowWidth / 2;
    circle.y = windowHeight / 2;
    dx = -dx;
}

void Ball::checkCollision(const SDL_Rect& rect)
{
    int closestX = std::clamp(circle.x, rect.x, rect.x + rect.w);
    int closestY = std::clamp(circle.y, rect.y, rect.y + rect.h);

    int distanceX = circle.x - closestX;
    int distanceY = circle.y - closestY;

    int distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

    if (distanceSquared < (circle.radius * circle.radius))
    {
        dx = -dx;
        
        if (circle.x < rect.x) {
            circle.x = rect.x - circle.radius;
        } else {
            circle.x = rect.x + rect.w + circle.radius;
        }
    }
}

void Ball::render(Renderer& renderer)
{
    renderer.drawCircle(circle, color);
}