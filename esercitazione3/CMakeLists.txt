cmake_minimum_required(VERSION 3.20)
project(esercizio1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE CXX FLAGS "${CMAKE CXX FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(esercizio1 esercizio1.cpp)