cmake_minimum_required(VERSION 3.10)
project(Pong CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
set(SDL2_DISABLE_INSTALL ON CACHE BOOL "" FORCE)

set(SDL2_TTF_SHARED OFF CACHE BOOL "" FORCE)
set(SDL2_TTF_STATIC ON CACHE BOOL "" FORCE)
set(SDL2_TTF_VENDORED ON CACHE BOOL "" FORCE)
set(SDL2_TTF_HARFBUZZ OFF CACHE BOOL "" FORCE)

if(WIN32)
    add_subdirectory(libs/SDL2)
    add_subdirectory(libs/SDL2_ttf)
elseif(APPLE)
    find_package(SDL2 CONFIG REQUIRED)
    find_package(SDL2_ttf CONFIG REQUIRED)
endif()

set(SOURCES
    src/main.cpp
    src/core/Game.cpp
    src/core/Renderer.cpp
    src/core/Window.cpp 
    src/core/InputHandler.cpp
    src/ai/BotController.cpp
    src/entity/Blocker.cpp
    src/entity/Ball.cpp
)

add_executable(Pong ${SOURCES})

target_include_directories(Pong PRIVATE src)

target_compile_definitions(Pong PRIVATE SDL_MAIN_HANDLED)
if(WIN32)
    target_link_libraries(Pong PRIVATE SDL2::SDL2-static SDL2_ttf)
else()
    target_link_libraries(Pong PRIVATE SDL2::SDL2 SDL2_ttf::SDL2_ttf)
endif()

add_custom_command(TARGET Pong POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:Pong>/assets
)