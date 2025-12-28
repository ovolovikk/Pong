#pragma once

#include <memory>

class Blocker;

class InputHandler
{
public:
    void handleInput(const std::shared_ptr<Blocker> &player);
};
