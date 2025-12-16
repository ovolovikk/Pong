#include "core/Game.hpp"

#include "core/Renderer.hpp"
#include "core/Window.hpp"
#include "entity/Blocker.hpp"

#include <iostream>

#include <SDL.h>

Game::Game(const std::string_view& title_, int width_, int height_)
{
    window = std::make_unique<Window>(title_, width_, height_);

    init();
    if(window) {
        update();
    }
}

Game::~Game()
{

}

void Game::update()
{
    while(is_running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT) {
                is_running = false;
            }
            //TODO
        }

        renderer->beginFrame();

        if (player) player->render(*renderer);
        if (bot) bot->render(*renderer);

        renderer->endFrame();
        
        SDL_Delay(16);
    }
}

void Game::init()
{
    renderer = std::make_unique<Renderer>(window->getSDLWindow());
    
    int w = window->getWidth();
    int h = window->getHeight();

    player = std::make_unique<Blocker>(50, (h / 2) - 50);
    bot = std::make_unique<Blocker>(w - 70, (h / 2) - 50);
}