cmake_minimum_required(VERSION 3.10)
project(Pong)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

include_directories(src)

add_definitions(-DSDL_MAIN_HANDLED)

add_executable(Pong 
              src/main.cpp
              src/core/Game.cpp
              src/core/Renderer.cpp
              src/core/Window.cpp 
              src/core/InputHandler.cpp
              src/ai/BotController.cpp
              src/entity/Blocker.cpp
              src/entity/Ball.cpp
              )

target_include_directories(Pong PRIVATE src)

target_link_libraries(Pong PRIVATE SDL2::SDL2 SDL2_ttf::SDL2_ttf)

add_custom_command(TARGET Pong POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:Pong>/assets
)

set_property(TARGET Pong PROPERTY CXX_STANDARD 20)
