#pragma once

#include "core/GameObject.hpp"

#include <memory>

struct SDL_Texture;

class Font;
class Renderer;

class Score : public GameObject
{
public:
    Score(std::shared_ptr<Font> font, int windowWidth);
    ~Score();

    void update() override {};
    void render(Renderer &renderer) override;

    void updateScore(int left, int right, Renderer &renderer);

private:

    std::shared_ptr<Font> m_font = nullptr;

    std::shared_ptr<SDL_Texture> m_leftTexture = nullptr;
    std::shared_ptr<SDL_Texture> m_rightTexture = nullptr;

    int m_lastLeft = -1, m_lastRight = -1;
    int m_windowWidth = 0;
};
