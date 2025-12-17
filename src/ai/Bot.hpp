#ifndef BOT_HPP
#define BOT_HPP

class Blocker;
class Ball;

class Bot
{
public:
    void update(Blocker& blocker, const Ball& ball);
};

#endif // BOT_HPP
