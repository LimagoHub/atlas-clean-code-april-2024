cmake_minimum_required(VERSION 3.25)
project(NimGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(NimGame main.cpp game/Game.h client/GameClient.h game/nim/NimGame.h game/nim/player/AbstractNimGamePlayer.h game/nim/player/HumanPlayer.h game/nim/player/ComputerPlayer.h io/Writer.h io/ConsoleWriter.h game/AbstractGame.h game/player/Player.h game/player/AbstractPlayer.h game/nim/player/OmaPlayer.h)
