
cmake_minimum_required(VERSION 3.20)

project(CodeGo VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(CodeGo
    src/main.cpp
    src/card.cpp
    include/MemoryBoard.hpp
    src/MemoryBoard.cpp
    src/Player.cpp
    src/Game.cpp
     include/Player.hpp
     include/Game.hpp
)

target_include_directories(CodeGo PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

