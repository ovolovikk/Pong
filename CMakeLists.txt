cmake_minimum_required(VERSION 3.10)
project(Pong)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(APPLE)
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
endif()

if(WIN32)
    set(SDL2_PATH "C:/Users/shona/Documents/libs/SDL2-2.32.10")
    include_directories(${SDL2_PATH}/include)
    include_directories(src)
    link_directories(${SDL2_PATH}/lib/x64)
endif()

add_definitions(-DSDL_MAIN_HANDLED)

add_executable(Pong 
    src/main.cpp 
    )

if(APPLE)
    target_link_libraries(Pong PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)
endif()

if(WIN32)
    target_link_libraries(Pong PRIVATE SDL2)
endif()

set_property(TARGET Pong PROPERTY CXX_STANDARD 20)
