#pragma once

#include <string>

struct SDL_Window;

class Window
{
public:
    Window(const std::string_view &title, int width, int height);
    ~Window();

    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    auto getSDLWindow() const { return m_window; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

private:
    SDL_Window *m_window;
    int m_width;
    int m_height;
};
