#ifndef BOT_CONTROLLER_HPP
#define BOT_CONTROLLER_HPP

class Blocker;
class Ball;

class BotController
{
public:
    void update(Blocker& blocker, const Ball& ball);
};

#endif // BOT_CONTROLLER_HPP
