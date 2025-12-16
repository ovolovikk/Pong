#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <memory>

#include <SDL.h>

class Window;
class Renderer;
class Blocker;

class Game
{
public:
    Game(const std::string_view& title_, int width_, int height_);
    ~Game();
    
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void update();

private:
    void init();

    SDL_Event event;

    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Blocker> player;
    std::unique_ptr<Blocker> bot;

    bool is_running = true;
};

#endif // GAME_HPP
