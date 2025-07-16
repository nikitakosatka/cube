cmake_minimum_required(VERSION 3.21.2)
project(rubiks_cube)

set(CMAKE_CXX_STANDARD 17)

add_executable(rubiks_cube
        main.cpp Cube.cpp Cube.h utils.h utils.cpp GeneticAlgorithm.cpp GeneticAlgorithm.h)
