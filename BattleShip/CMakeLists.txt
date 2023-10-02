cmake_minimum_required(VERSION 3.15.3)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp Board.cpp Board.h Game.cpp Game.h Move.cpp Move.h Player.cpp Player.h Ship.h Validation.cpp Validation.h)
