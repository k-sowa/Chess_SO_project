cmake_minimum_required(VERSION 3.27)
project(chess_projekt C)

set(CMAKE_C_STANDARD 11)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(chess_projekt main.c
        move_validation.c
        move_validation.h
        menu.c
        menu.h
        checkmate_engine.c
        checkmate_engine.h
)

target_link_libraries(chess_projekt ${CURSES_LIBRARIES})