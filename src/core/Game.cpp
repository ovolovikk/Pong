#include "core/Game.hpp"

#include "core/Renderer.hpp"
#include "core/Window.hpp"
#include "entity/Blocker.hpp"
#include "entity/Ball.hpp"

#include <iostream>

Game::Game(const std::string_view &title_, int width_, int height_)
{
    window = std::make_unique<Window>(title_, width_, height_);

    init();
    if (window)
    {
        run();
    }
}

Game::~Game() = default;

void Game::run()
{
    if (!player || !bot || !ball || !renderer)
    {
        std::cerr << "Game entities not initialized!" << std::endl;
        return;
    }

    while (is_running)
    {
        handleEvents();
        update();
        render();
        SDL_Delay(16);
    }
}

void Game::handleEvents()
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            is_running = false;
        }

        if (state == GameState::GameOver && event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_RETURN)
            {
                resetGame();
            }
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                is_running = false;
            }
        }
    }
}

void Game::update()
{
    if (state != GameState::Playing)
        return;

    inputHandler.handleInput(*player);
    botController.update(*bot, *ball);

    player->update();
    bot->update();
    ball->update();

    ball->checkCollision(player->getRect());
    ball->checkCollision(bot->getRect());

    if (ball->getX() < 0)
    {
        rightScore++;
        ball->reset();
    }
    else if (ball->getX() > window->getWidth())
    {
        leftScore++;
        ball->reset();
    }

    if (leftScore >= MAX_SCORE || rightScore >= MAX_SCORE)
    {
        state = GameState::GameOver;
    }
}

void Game::render()
{
    renderer->beginFrame();

    if (state == GameState::Playing)
    {
        player->render(*renderer);
        bot->render(*renderer);
        ball->render(*renderer);
        renderer->drawText(std::to_string(leftScore),
                           200, 50,
                           32, {255, 255, 255, 255});
        renderer->drawText(std::to_string(rightScore),
                           window->getWidth() - 200, 50,
                           32, {255, 255, 255, 255});
    }
    else if (state == GameState::GameOver)
    {
        renderer->drawText("GAME OVER",
                           window->getWidth() / 2 - 100, window->getHeight() / 2 - 50,
                           48, {255, 0, 0, 255});
        renderer->drawText("Press ENTER to Restart",
                           window->getWidth() / 2 - 190, window->getHeight() / 2 + 20,
                           24, {255, 255, 255, 255});
    }

    renderer->endFrame();
}

void Game::resetGame()
{
    leftScore = 0;
    rightScore = 0;
    ball->reset();
    state = GameState::Playing;
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