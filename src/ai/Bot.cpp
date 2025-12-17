#include "ai/Bot.hpp"
#include "entity/Blocker.hpp"
#include "entity/Ball.hpp"
#include "helpers/Circle.hpp"

void Bot::update(Blocker& blocker, const Ball& ball)
{
    const Circle& ballCircle = ball.getCircle();
    int ballY = ballCircle.y;
    int blockerY = blocker.getY() + blocker.getHeight() / 2;

    if (ballY < blockerY - 10) {
        blocker.setDirection(-1);
    } else if (ballY > blockerY + 10) {
        blocker.setDirection(1);
    } else {
        blocker.setDirection(0);
    }
}
