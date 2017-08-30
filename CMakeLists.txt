cmake_minimum_required(VERSION 3.6)
project(penes)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(SOURCE_FILES
        src/cpuop.c
        src/gbcpu.c
        src/gbmem.c
        src/gbreg.c
        src/penes.c)

add_executable(penes ${SOURCE_FILES})