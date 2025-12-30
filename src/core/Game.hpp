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

    bool isValid() const { return m_is_valid; }
    void run();

private:
    void init();
    void handleEvents();
    void update();
    void render();
    void resetGame();

    SDL_Event m_event;

    std::shared_ptr<Window> m_window = nullptr;
    std::shared_ptr<Renderer> m_renderer = nullptr;
    std::shared_ptr<Blocker> m_player = nullptr;
    std::shared_ptr<Blocker> m_bot = nullptr;
    std::shared_ptr<Ball> m_ball = nullptr;
    std::shared_ptr<Font> m_scoreFont = nullptr;
    std::shared_ptr<Font> m_gameOverFont = nullptr;
    std::shared_ptr<Score> m_score = nullptr;

    BotController m_botController;
    InputHandler m_inputHandler;

    GameState m_state = GameState::Playing;
    uint8_t m_leftScore = 0;
    uint8_t m_rightScore = 0;
    static constexpr auto MAX_SCORE = 1;

    bool m_is_running = true;
    bool m_is_valid = false;
};
