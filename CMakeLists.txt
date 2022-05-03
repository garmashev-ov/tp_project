cmake_minimum_required(VERSION 3.0)
project(TP)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(BattleShip cpp_files/main.cpp)
