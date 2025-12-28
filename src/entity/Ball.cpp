#include "Ball.hpp"
#include "core/Renderer.hpp"

#include <SDL.h>
#include <cmath>
#include <algorithm>

Ball::Ball(const Circle &p, SDL_Color color, int windowWidth, int windowHeight)
        : m_circle(p), m_color(color),
            m_windowWidth(windowWidth), m_windowHeight(windowHeight),
            m_dx(4.0f), m_dy(4.0f), m_speed(4.0f)
{
}

Ball::~Ball() = default;

void Ball::update()
{
    m_circle.x += m_dx;
    m_circle.y += m_dy;

    if (m_circle.y - m_circle.radius < 0)
    {
        m_circle.y = m_circle.radius;
        m_dy = -m_dy;
    }
    if (m_circle.y + m_circle.radius > m_windowHeight)
    {
        m_circle.y = m_windowHeight - m_circle.radius;
        m_dy = -m_dy;
    }
}

void Ball::reset()
{
    m_circle.x = m_windowWidth / 2;
    m_circle.y = m_windowHeight / 2;
    m_speed = 4.0f;
    m_dx = (m_dx > 0 ? -1 : 1) * m_speed;
    m_dy = (m_dy > 0 ? 1 : -1) * m_speed;
}

void Ball::checkCollision(const SDL_Rect &rect)
{
    int closestX = std::clamp(m_circle.x, rect.x, rect.x + rect.w);
    int closestY = std::clamp(m_circle.y, rect.y, rect.y + rect.h);

    int distanceX = m_circle.x - closestX;
    int distanceY = m_circle.y - closestY;

    int distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

    if (distanceSquared < (m_circle.radius * m_circle.radius))
    {
        m_speed += 1.0f;

        float length = std::sqrt(m_dx * m_dx + m_dy * m_dy);
        if (length != 0)
        {
            m_dx = (m_dx / length) * m_speed;
            m_dy = (m_dy / length) * m_speed;
        }

        m_dx = -m_dx;

        if (m_circle.x < rect.x)
        {
            m_circle.x = rect.x - m_circle.radius;
        }
        else
        {
            m_circle.x = rect.x + rect.w + m_circle.radius;
        }
    }
}

void Ball::render(Renderer &renderer)
{
    renderer.drawCircle(m_circle, m_color);
}