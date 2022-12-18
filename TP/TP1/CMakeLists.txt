cmake_minimum_required(VERSION 3.24)
project(TP1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TP1
        main.c
        main.h app.c app.c interface.c)
