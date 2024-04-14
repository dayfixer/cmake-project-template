

message(STATUS CMAKE_SOURCE_DIR:${CMAKE_SOURCE_DIR})

if(Demo_Fetch_wxWidgets)
    include(FetchContent)
    FetchContent_Declare(
        wxWidgets
        GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
        GIT_SHALLOW ON
    )
    FetchContent_MakeAvailable(wxWidgets)
endif()

if (Demo_BUILD_GUI)
    add_executable(Demo WIN32 main_gui.cpp)
else()
    add_executable(Demo main.cpp)
endif()

target_include_directories(Demo
    PRIVATE
        ${CMAKE_DIR}/include/Demo
)

target_link_libraries(Demo
    PRIVATE
        Demo::Chinese
        Demo::English
        wx::base
)

if (Demo_BUILD_GUI)
    target_link_libraries(Demo
        PRIVATE
            wx::core
            wx::net
    )
endif()

