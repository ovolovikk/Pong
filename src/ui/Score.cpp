#include "Score.hpp"

#include "core/Renderer.hpp"
#include "ui/Font.hpp"
#include "helpers/Colors.hpp"

#include <SDL.h>

Score::Score(std::shared_ptr<Font> font, int windowWidth)
    : m_font(font), m_windowWidth(windowWidth)
{
}

Score::~Score() = default;

void Score::updateScore(int left, int right, Renderer &renderer)
{
    if (left == m_lastLeft && right == m_lastRight)
        return;

    m_lastLeft = left;
    m_lastRight = right;
    
    auto raw_tex = m_font->renderText(renderer.getSDLRenderer(), std::to_string(left), m_color);
    m_leftTexture.reset(raw_tex, SDL_DestroyTexture);

    auto raw_tex_r = m_font->renderText(renderer.getSDLRenderer(), std::to_string(right), m_color);
    m_rightTexture.reset(raw_tex_r, SDL_DestroyTexture);
}

void Score::render(Renderer &renderer)
{
    renderer.drawTexture(m_leftTexture.get(),
                         static_cast<int>(m_windowWidth / POSITION_DIVIDER),
                         DISTANCE_Y);
    renderer.drawTexture(m_rightTexture.get(),
                         static_cast<int>(m_windowWidth * 3.f / POSITION_DIVIDER),
                         DISTANCE_Y);
}