cmake_minimum_required(VERSION 3.6)
project(damegame C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall")
set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/dependencies/SDL2-2.0.5/include)
set(SDL2_LIBRARY_DIR ${CMAKE_CURRENT_LIST_DIR}/dependencies/SDL2-2.0.5/lib)

include_directories(include)
include_directories(${SDL2_INCLUDE_DIRS})

if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(SDL2_LIBRARIES "${SDL2_LIBRARY_DIR}/x64/SDL2main.lib;${SDL2_LIBRARY_DIR}/x64/SDL2.lib")
    execute_process(COMMAND cmake -E copy ${SDL2_LIBRARY_DIR}/x64/SDL2.dll ${CMAKE_CURRENT_BINARY_DIR}/SDL2.dll)
else ()
    set(SDL2_LIBRARIES "${SDL2_LIBRARY_DIR}/x86/SDL2main.lib;${SDL2_LIBRARY_DIR}/x86/SDL2.lib")
    execute_process(COMMAND cmake -E copy ${SDL2_LIBRARY_DIR}/x86/SDL2.dll ${CMAKE_CURRENT_BINARY_DIR}/SDL2.dll)
endif ()

add_executable(damegame ${SOURCE_FILES}
        src/cpuop.c src/cputable.c src/damegame.c src/error.c src/gbcpu.c src/gbmem.c src/gbreg.c src/sdl_wrapper.c)
target_include_directories(damegame PUBLIC ${SDL2_INCLUDE_DIR})
target_link_libraries(damegame ${SDL2_LIBRARIES})

