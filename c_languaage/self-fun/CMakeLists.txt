cmake_minimum_required(VERSION 3.26)
project(self_fun C)

set(CMAKE_C_STANDARD 11)

add_executable(self_fun main.c)
add_subdirectory(luogu)
add_subdirectory(self-learn)
add_executable(trail mergesort.c)
add_subdirectory(stdlib)
add_subdirectory(string)