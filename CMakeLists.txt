cmake_minimum_required(VERSION 3.15)
project(Game_Of_Life)

set(CMAKE_CXX_STANDARD 20)

add_executable(Game_Of_Life main.cpp Cell.cpp Board.cpp)