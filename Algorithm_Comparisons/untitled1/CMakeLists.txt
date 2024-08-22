cmake_minimum_required(VERSION 3.26)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled1 main.cpp
        all_algorithms.h
        gusfield_z..cpp
        rabin_karp.cpp
        fsm.cpp
        kmp.cpp
        sunday.cpp
        brute_force.cpp)
