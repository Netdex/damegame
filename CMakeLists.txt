cmake_minimum_required(VERSION 3.6)
project(damegame)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
include_directories(include)

file(GLOB SOURCE_FILES "src/*.c")

add_executable(damegame ${SOURCE_FILES})