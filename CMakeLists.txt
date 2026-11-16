cmake_minimum_required(VERSION 3.20)
project(lab-5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(/W4 /EHsc)

add_executable(lab5 main.cpp)
