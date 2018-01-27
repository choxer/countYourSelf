cmake_minimum_required(VERSION 3.9)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)

add_executable(counted source/main.c source/mainMenue.c header/mainMenue.h source/habits.c header/habits.h header/datastructures.h source/showCurrent.c header/showCurrent.h)