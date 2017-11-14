cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Board.cpp Board.h ReversiGame.cpp ReversiGame.h TurnsManager.cpp TurnsManager.h Participant.cpp Participant.h Cell.h GameUtilities.cpp GameUtilities.h Player.h Player.cpp AI.h AI.cpp MovesEvaluator.h MovesEvaluator.cpp)
add_executable(untitled ${SOURCE_FILES})