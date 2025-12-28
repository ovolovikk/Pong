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

    std::unique_ptr<Window> m_window;
    std::unique_ptr<Renderer> m_renderer;
    std::shared_ptr<Blocker> m_player;
    std::shared_ptr<Blocker> m_bot;
    std::shared_ptr<Ball> m_ball;
    std::unique_ptr<Font> m_scoreFont;
    std::unique_ptr<Font> m_gameOverFont;

    BotController m_botController;
    InputHandler m_inputHandler;

    GameState m_state = GameState::Playing;
    uint8_t m_leftScore = 0;
    uint8_t m_rightScore = 0;
    static constexpr auto MAX_SCORE = 5;

    bool m_is_running = true;
    bool m_is_valid = false;
};
