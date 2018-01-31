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
        main.c source/tools.c header/tools.h source/timeStructure.c header/timeStructure.h source/save.c header/save.h source/list.c header/list.h source/day.c)
