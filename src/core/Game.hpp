#ifndef GAME_HPP
#define GAME_HPP

#include "core/Window.hpp"
#include "core/Renderer.hpp"

#include <string>
#include <memory>

#include <SDL.h>

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

    bool is_running = true;
};

#endif // GAME_HPP
