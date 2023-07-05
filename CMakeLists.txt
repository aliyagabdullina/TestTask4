cmake_minimum_required(VERSION 3.24)
project(testtask)

set(CMAKE_CXX_STANDARD 17)

set(MAIN_SOURCES main.cpp)
set(RANDOM_SOURCES random.cpp)
set(RANDOM_HEADERS random.h)

add_executable(testtask main.cpp graph.cpp graph.h random.cpp random.h)
