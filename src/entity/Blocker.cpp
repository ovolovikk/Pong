#include "Blocker.hpp"

#include "core/Renderer.hpp"

Blocker::Blocker(int x, int y, int windowHeight_) 
    : width(20), height(100), 
      windowHeight(windowHeight_), direction(0)
{
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
}

Blocker::~Blocker() = default;

void Blocker::update()
{
    rect.y += direction * SPEED;

    if (rect.y < 0) {
        rect.y = 0;
    }
    if (rect.y + height > windowHeight) {
        rect.y = windowHeight - height;
    }
}

void Blocker::render(Renderer& renderer)
{
    renderer.drawRect(rect);
}