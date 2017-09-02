cmake_minimum_required(VERSION 3.6)
project(damegame)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

file(GLOB SOURCE_FILES "src/*.c")

add_executable(damegame ${SOURCE_FILES})