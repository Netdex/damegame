cmake_minimum_required(VERSION 3.6)
project(damegame)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
include_directories(include)

add_executable(damegame ${SOURCE_FILES} src/cpuop.c src/cputable.c src/damegame.c src/error.c src/gbcpu.c src/gbmem.c src/gbreg.c)