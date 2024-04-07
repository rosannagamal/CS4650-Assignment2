cmake_minimum_required(VERSION 3.27)
project(CS4650_A2)

set(CMAKE_CXX_STANDARD 17)

add_executable(CS4650_A2 main.cpp
        State.h
        StateManager.cpp
        StateManager.h
        Idle.cpp
        Idle.h
        Walking.cpp
        Walking.h
        Jumping.cpp
        Jumping.h)
