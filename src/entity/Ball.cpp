#include "Ball.hpp"

#include "core/Renderer.hpp"
#include "helpers/Colors.hpp"
#include "helpers/Params.hpp"

#include <SDL.h>

#include <cmath>
#include <algorithm>

Ball::Ball(float x, float y, int radius, int windowWidth, int windowHeight)
    : m_windowWidth(windowWidth), m_windowHeight(windowHeight),
      m_dx(Params::INITIAL_SPEED), m_dy(Params::INITIAL_SPEED), m_speed(Params::INITIAL_SPEED)
{
    m_x = x;
    m_y = y;
    m_w = radius * 2;
    m_h = radius * 2;
    m_color = Colors::White;
}

Ball::~Ball() = default;

void Ball::update()
{
    m_x += m_dx;
    m_y += m_dy;

    float radius = static_cast<float>(m_w) / 2.0f;

    if (m_y - radius < 0.0f)
    {
        m_y = radius;
        m_dy = -m_dy;
    }
    else if (m_y + radius > static_cast<float>(m_windowHeight))
    {
        m_y = static_cast<float>(m_windowHeight) - radius;
        m_dy = -m_dy;
    }
}

void Ball::reset()
{
    m_x = static_cast<float>(m_windowWidth) / 2.0f;
    m_y = static_cast<float>(m_windowHeight) / 2.0f;
    m_speed = Params::INITIAL_SPEED;
    m_dx = (m_dx > 0 ? -1.0f : 1.0f) * m_speed;
    m_dy = (m_dy > 0 ? 1.0f : -1.0f) * m_speed;
}

void Ball::checkCollision(const SDL_Rect &rect)
{
    float radius = static_cast<float>(m_w) / 2.0f;

    float closestX = std::clamp(m_x, static_cast<float>(rect.x), static_cast<float>(rect.x + rect.w));
    float closestY = std::clamp(m_y, static_cast<float>(rect.y), static_cast<float>(rect.y + rect.h));

    float distanceX = m_x - closestX;
    float distanceY = m_y - closestY;

    float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

    if (distanceSquared < (radius * radius))
    {
        m_speed += Params::SPEED_INCREMENT;

        float length = std::sqrt(m_dx * m_dx + m_dy * m_dy);
        if (length != 0)
        {
            m_dx = (m_dx / length) * m_speed;
            m_dy = (m_dy / length) * m_speed;
        }

        m_dx = -m_dx;

        if (m_x < static_cast<float>(rect.x))
            m_x = static_cast<float>(rect.x) - radius;
        else
            m_x = static_cast<float>(rect.x + rect.w) + radius;
    }
}

void Ball::render(Renderer &renderer)
{
    renderer.setDrawColor(m_color);
    renderer.drawCircle(static_cast<int>(m_x), static_cast<int>(m_y), m_w / 2);
}

float Ball::getX() const
{
    return m_x;
}

float Ball::getY() const
{
    return m_y;
}