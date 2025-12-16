#include "Blocker.hpp"

#include "core/Renderer.hpp"

Blocker::Blocker(int x, int y) : width(20), height(100)
{
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
}

Blocker::~Blocker() = default;

void Blocker::update()
{
    //TODO MOVE LOGIC
}

void Blocker::render(Renderer& renderer)
{
    renderer.drawRect(rect);
}