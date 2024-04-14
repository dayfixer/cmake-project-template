cmake_minimum_required(VERSION 3.24)
project(English C CXX)

add_library(English SHARED)
add_library(Demo::English ALIAS English)

target_sources(English
    PRIVATE 
        src/speak.cpp
)

target_include_directories(English
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/English
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(English
    PRIVATE
        ENGLISH_EXPORT
)