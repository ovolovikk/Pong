#pragma once

#include <string>
#include <memory>

struct SDL_Window;

class Window
{
public:
    Window(const std::string_view &title, int width, int height);
    ~Window();

    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    SDL_Window *getSDLWindow() const { return m_window.get(); }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

private:
    std::shared_ptr<SDL_Window> m_window = nullptr;
    int m_width;
    int m_height;
};
