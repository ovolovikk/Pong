#include "core/Game.hpp"

#include <iostream>

#include <SDL.h>
#include <SDL2_image/SDL_image.h>

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
        
        renderer->draw();
        renderer->endFrame();
        
        SDL_Delay(16);
    }
}

void Game::init()
{
    renderer = std::make_unique<Renderer>(window->getSDLWindow());
}