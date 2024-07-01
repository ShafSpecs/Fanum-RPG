cmake_minimum_required(VERSION 3.28)
project(FanumRPG)

set(CMAKE_CXX_STANDARD 20)

add_executable(FanumRPG main.cpp
        Player.cpp
        Player.h
        Game.cpp
        Game.h)
