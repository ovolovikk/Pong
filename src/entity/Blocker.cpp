#include "Blocker.hpp"

#include "core/Renderer.hpp"

Blocker::Blocker(int x, int y, int windowHeight_)
    : m_width(20), m_height(100),
      m_windowHeight(windowHeight_), m_direction(0)
{
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = m_width;
    m_rect.h = m_height;
}

Blocker::~Blocker() = default;

void Blocker::update()
{
    m_rect.y += m_direction * SPEED;

    if (m_rect.y < 0)
    {
        m_rect.y = 0;
    }
    if (m_rect.y + m_height > m_windowHeight)
    {
        m_rect.y = m_windowHeight - m_height;
    }
}

void Blocker::render(Renderer &renderer)
{
    renderer.drawRect(m_rect);
}