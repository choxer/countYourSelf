cmake_minimum_required(VERSION 3.9)
project(countYourSelf)

set(CMAKE_CXX_STANDARD 11)

add_executable(countYourSelf
        header/datastructures.h
        header/habits.h
        header/mainMenue.h
        header/showCurrent.h
        source/habits.c
        source/mainMenue.c
        source/showCurrent.c
        main.c)
