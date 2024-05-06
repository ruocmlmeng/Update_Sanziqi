cmake_minimum_required(VERSION 3.28)
project(FirstGame C)

set(CMAKE_C_STANDARD 11)

add_executable(FirstGame test.c
        game.c
        game.h)
