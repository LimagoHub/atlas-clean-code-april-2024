cmake_minimum_required(VERSION 3.25)
project(NimGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(NimGame main.cpp game/Game.h client/GameClient.h game/nim/NimGame.h)
