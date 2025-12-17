#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

struct SDL_Window;

class Window
{
public:
    Window(const std::string_view &title, int width_, int height_);
    ~Window();

    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    auto getSDLWindow() const { return window; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    SDL_Window *window;
    int width;
    int height;
};

#endif // WINDOW_HPP
