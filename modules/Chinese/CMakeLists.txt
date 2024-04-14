cmake_minimum_required(VERSION 3.24)
project(Chinese C CXX)

add_library(Chinese STATIC)
add_library(Demo::Chinese ALIAS Chinese)

target_sources(Chinese
    PRIVATE 
        src/write.cpp
)

target_include_directories(Chinese
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Chinese
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)