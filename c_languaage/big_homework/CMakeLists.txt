cmake_minimum_required(VERSION 3.27)
project(big_homework C)

set(CMAKE_C_STANDARD 17)
add_executable(try run.c)

include_directories(include)


target_link_libraries(try mingw32)
target_link_libraries(try SDL2main)
target_link_libraries(try SDL2)
target_link_libraries(try SDL2_image)
target_link_libraries(try SDL2_ttf)
target_link_libraries(try SDL2_mixer)
