cmake_minimum_required(VERSION 3.31)
project(Lapse)

set(CMAKE_CXX_STANDARD 20)

set(LIBRARY
        lapse.h
        lapse.cpp
)

add_library(lapse SHARED ${LIBRARY})