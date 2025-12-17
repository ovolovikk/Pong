#include "core/Game.hpp"

#include "core/Renderer.hpp"
#include "core/Window.hpp"
#include "entity/Blocker.hpp"
#include "entity/Ball.hpp"

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
    if (!player || !bot || !ball || !renderer) {
        std::cerr << "Game entities not initialized!" << std::endl;
        return;
    }

    while(is_running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT) {
                is_running = false;
            }
            //TODO
        }

        inputHandler.handleInput(*player);
        botController.update(*bot, *ball);

        player->update();
        bot->update();
        ball->update();
        
        ball->checkCollision(player->getRect());
        ball->checkCollision(bot->getRect());

        renderer->beginFrame();

        player->render(*renderer);
        bot->render(*renderer);
        ball->render(*renderer);

        renderer->endFrame();
        
        SDL_Delay(16);
    }
}

void Game::init()
{
    renderer = std::make_unique<Renderer>(window->getSDLWindow());
    
    int w = window->getWidth();
    int h = window->getHeight();

    player = std::make_unique<Blocker>(50, (h / 2) - 50, h);
    ball = std::make_unique<Ball>(Circle{w / 2, h / 2, 10}, SDL_Color{255, 255, 255, 255}, w, h);
    bot = std::make_unique<Blocker>(w - 70, (h / 2) - 50, h);
}