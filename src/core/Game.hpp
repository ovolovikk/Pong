#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <memory>

#include <SDL.h>

#include "core/InputHandler.hpp"
#include "ai/BotController.hpp"

class Window;
class Renderer;
class Blocker;
class Ball;

enum class GameState
{
    Playing,
    GameOver
};

class Game
{
public:
    Game(const std::string_view &title_, int width_, int height_);
    ~Game();

    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

    void run();

private:
    void init();
    void handleEvents();
    void update();
    void render();
    void resetGame();

    SDL_Event event;

    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Blocker> player;
    std::unique_ptr<Blocker> bot;
    std::unique_ptr<Ball> ball;

    BotController botController;
    InputHandler inputHandler;

    GameState state = GameState::Playing;
    uint8_t leftScore = 0;
    uint8_t rightScore = 0;
    static constexpr auto MAX_SCORE = 5;

    bool is_running = true;
};

#endif // GAME_HPP
