#pragma once

#include <memory>

class Blocker;
class Ball;

class BotController
{
public:
    void update(const std::shared_ptr<Blocker> &blocker, const std::shared_ptr<Ball> &ball);
};
