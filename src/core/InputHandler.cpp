#include "core/InputHandler.hpp"
#include "entity/Blocker.hpp"
#include <SDL.h>

void InputHandler::handleInput(Blocker& player)
{
    const Uint8* state = SDL_GetKeyboardState(NULL);
    
    int direction = 0;
    if (state[SDL_SCANCODE_W]) {
        direction = -1;
    }
    if (state[SDL_SCANCODE_S]) {
        direction = 1;
    }
    player.setDirection(direction);
}
