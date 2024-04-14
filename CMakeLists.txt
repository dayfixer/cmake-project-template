cmake_minimum_required(VERSION 3.24)
project(cmake-project-template-Demo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

option(Demo_BUILD_GUI "Build Gui" OFF)
option(Demo_BUILD_TEST "Build test" TRUE)
option(Demo_Fetch_wxWidgets "Fetch wxWidgets" OFF)

set(wxBUILD_SHARED   OFF)

if(Demo_BUILD_GUI)
    set(wxUSE_GUI        ON)
    set(wxBUILD_DEMOS    ON)
    set(wxBUILD_SAMPLES  "ALL")
else()
    set(wxUSE_GUI        OFF)
endif()

if (NOT Demo_Fetch_wxWidgets)
    add_subdirectory(vendors/wxWidgets-3.2.4)
endif()

# CMake helper functions
include(cmake/Helpers.cmake)

# Vendors
add_subdirectory(vendors)

# Libraries: Shared/Static
add_subdirectory(modules)

# Project Sources
add_subdirectory(src)

# Tests
if(Demo_BUILD_TEST)
    add_subdirectory(tests)
endif()

