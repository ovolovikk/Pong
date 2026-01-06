#pragma once

#include <string>
#include <memory>

#include "core/InputHandler.hpp"
#include "ai/BotController.hpp"

#include <SDL.h>

class Window;
class Renderer;
class Blocker;
class Ball;
class Font;
class Score;

enum class GameState
{
    Playing,
    GameOver
};

class Game
{
public:
    Game(const std::string_view &title, int width, int height);
    ~Game();

    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

    bool isValid() const;
    void run();

private:
    void init();
    void handleEvents();
    void update();
    void render();
    void resetGame();

    SDL_Event m_event;

    std::shared_ptr<Window> m_window;
    std::shared_ptr<Renderer> m_renderer;
    std::shared_ptr<Blocker> m_player;
    std::shared_ptr<Blocker> m_bot;
    std::shared_ptr<Ball> m_ball;
    std::shared_ptr<Font> m_scoreFont;
    std::shared_ptr<Font> m_gameOverFont;
    std::shared_ptr<Score> m_score;

    BotController m_botController;
    InputHandler m_inputHandler;

    GameState m_state = GameState::Playing;
    uint8_t m_leftScore = 0;
    uint8_t m_rightScore = 0;

    bool m_is_running = true;
    bool m_is_valid = false;
};
