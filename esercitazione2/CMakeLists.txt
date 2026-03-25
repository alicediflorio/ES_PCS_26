cmake_minimum_required(VERSION 3.20)
project(esercizio2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE CXX FLAGS "${CMAKE CXX FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(esercizio2 esercizio2.cpp)