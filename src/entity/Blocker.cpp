#include "Blocker.hpp"

#include "helpers/Colors.hpp"
#include "core/Renderer.hpp"
#include "helpers/Params.hpp"

Blocker::Blocker(int x, int y, int windowHeight)
    : m_windowHeight(windowHeight), m_direction(0)
{
    m_x = static_cast<float>(x);
    m_y = static_cast<float>(y);
    m_w = Params::BLOCKER_WIDTH;
    m_h = Params::BLOCKER_HEIGHT;
    m_color = Colors::White;
}

Blocker::~Blocker() = default;

void Blocker::update()
{
    m_y += static_cast<float>(m_direction * Params::SPEED);

    if (m_y < 0)
    {
        m_y = 0;
    }
    if (m_y + static_cast<float>(m_h) > static_cast<float>(m_windowHeight))
    {
        m_y = static_cast<float>(m_windowHeight - m_h);
    }

    m_rect = {static_cast<int>(m_x), static_cast<int>(m_y), m_w, m_h};
}

void Blocker::render(Renderer &renderer)
{
    renderer.setDrawColor(m_color);
    SDL_Rect rect = {static_cast<int>(m_x), static_cast<int>(m_y), m_w, m_h};
    renderer.drawRect(rect);
}

void Blocker::setDirection(int direction)
{
    m_direction = direction;
}

int Blocker::getHeight() const
{
    return m_h;
}

int Blocker::getY() const
{
    return m_rect.y;
}
    
const SDL_Rect &Blocker::getRect() const
{
    return m_rect;
};