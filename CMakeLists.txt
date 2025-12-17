cmake_minimum_required(VERSION 3.10)
project(Pong)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(APPLE)
    set(CMAKE_FIND_FRAMEWORK LAST)
    find_package(SDL2 REQUIRED)
    find_package(SDL2_ttf REQUIRED)
endif()

if(WIN32)
    set(SDL2_PATH "C:/Users/shona/Documents/libs/SDL2-2.32.10")
    include_directories(${SDL2_PATH}/include)
    include_directories(src)
    link_directories(${SDL2_PATH}/lib/x64)

    file(GLOB SDL2_DLLS "${SDL2_PATH}/lib/x64/*.dll")
endif()

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

if(APPLE)
    target_link_libraries(Pong PRIVATE SDL2::SDL2 SDL2_ttf::SDL2_ttf)
endif()

if(WIN32)
    target_link_libraries(Pong PRIVATE SDL2)

    add_custom_command(TARGET Pong POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${SDL2_DLLS}
        $<TARGET_FILE_DIR:Pong>
        COMMENT "Copying SDL2 DLLs to output directory")
endif()

add_custom_command(TARGET Pong POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:Pong>/assets
)

set_property(TARGET Pong PROPERTY CXX_STANDARD 20)
