cmake_minimum_required(VERSION 3.4)

project(solution)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_library(solution source/solution.cpp)
add_library(database source/database.cpp)

add_executable(main application/main.cpp)
target_link_libraries(main solution database)