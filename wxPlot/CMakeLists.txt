cmake_minimum_required(VERSION 3.23.0)
project(wxPlot LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

add_executable(wxPlot)
target_sources(wxPlot PRIVATE "Main.cpp" "Main.h")
target_include_directories(wxPlot PRIVATE "${PROJECT_SOURCE_DIR}")
add_subdirectory("src")
target_link_libraries(wxPlot ${wxWidgets_LIBRARIES})