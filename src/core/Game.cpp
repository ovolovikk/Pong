#include "core/Game.hpp"

#include "core/Renderer.hpp"
#include "core/Window.hpp"
#include "entity/Blocker.hpp"
#include "entity/Ball.hpp"
#include "ui/Font.hpp"

#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>

Game::Game(const std::string_view &title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return;
    }

    if (TTF_Init() != 0)
    {
        std::cerr << "TTF_Init failed: " << TTF_GetError() << std::endl;
        return;
    }

    m_scoreFont = std::make_unique<Font>("assets/font.ttf", 32);
    m_gameOverFont = std::make_unique<Font>("assets/font.ttf", 48);

    m_is_valid = true;

    m_window = std::make_unique<Window>(title, width, height);
    init();
}

Game::~Game()
{
    if (m_is_valid)
    {
        m_renderer.reset();
        m_window.reset();

        m_gameOverFont.reset();
        m_scoreFont.reset();

        TTF_Quit();
        SDL_Quit();
    }
}

void Game::run()
{
    if (!m_player || !m_bot || !m_ball || !m_renderer)
    {
        std::cerr << "Game entities not initialized!" << std::endl;
        return;
    }

    while (m_is_running)
    {
        handleEvents();
        update();
        render();
        SDL_Delay(16);
    }
}

void Game::handleEvents()
{
    while (SDL_PollEvent(&m_event))
    {
        if (m_event.type == SDL_QUIT)
        {
            m_is_running = false;
        }

        if (m_state == GameState::GameOver && m_event.type == SDL_KEYDOWN)
        {
            if (m_event.key.keysym.sym == SDLK_RETURN)
            {
                resetGame();
            }
            if (m_event.key.keysym.sym == SDLK_ESCAPE)
            {
                m_is_running = false;
            }
        }
    }
}

void Game::update()
{
    if (m_state != GameState::Playing)
        return;

    m_inputHandler.handleInput(m_player);
    m_botController.update(m_bot, m_ball);

    m_player->update();
    m_bot->update();
    m_ball->update();

    m_ball->checkCollision(m_player->getRect());
    m_ball->checkCollision(m_bot->getRect());

    if (m_ball->getX() < 0)
    {
        m_rightScore++;
        m_ball->reset();
    }
    else if (m_ball->getX() > m_window->getWidth())
    {
        m_leftScore++;
        m_ball->reset();
    }

    if (m_leftScore >= MAX_SCORE || m_rightScore >= MAX_SCORE)
    {
        m_state = GameState::GameOver;
    }
}

void Game::render()
{
    if (!m_renderer)
        return;

    m_renderer->beginFrame();

    if (m_state == GameState::Playing)
    {
        m_player->render(*m_renderer);
        m_bot->render(*m_renderer);
        m_ball->render(*m_renderer);

        m_renderer->drawText(
            std::to_string(m_leftScore),
            m_window->getWidth() / 4,
            30,
            32,
            SDL_Color{255, 255, 255, 255}
        );

        m_renderer->drawText(
            std::to_string(m_rightScore),
            m_window->getWidth() * 3 / 4,
            30,
            32,
            SDL_Color{255, 255, 255, 255}
        );
    }
    else if (m_state == GameState::GameOver)
    {
        m_renderer->drawText(
            "GAME OVER",
            m_window->getWidth() / 2 - 140,
            m_window->getHeight() / 2 - 80,
            48,
            SDL_Color{255, 0, 0, 255}
        );

        m_renderer->drawText(
            "Press ENTER to restart",
            m_window->getWidth() / 2 - 200,
            m_window->getHeight() / 2,
            24,
            SDL_Color{255, 255, 255, 255}
        );
    }

    m_renderer->endFrame();
}



void Game::resetGame()
{
    m_leftScore = 0;
    m_rightScore = 0;
    m_ball->reset();
    m_state = GameState::Playing;
}

void Game::init()
{
    m_renderer = std::make_unique<Renderer>(m_window->getSDLWindow());

    int w = m_window->getWidth();
    int h = m_window->getHeight();

    m_player = std::make_shared<Blocker>(50, (h / 2) - 50, h);
    m_ball = std::make_shared<Ball>(Circle{w / 2, h / 2, 10}, SDL_Color{255, 255, 255, 255}, w, h);
    m_bot = std::make_shared<Blocker>(w - 70, (h / 2) - 50, h);
}