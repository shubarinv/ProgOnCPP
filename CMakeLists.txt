cmake_minimum_required(VERSION 3.13)
project(ProgOnCPP)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/ ${CMAKE_MODULE_PATH})
find_package(SDL REQUIRED)
find_package ( SDL_ttf REQUIRED )
find_package ( SDL_draw REQUIRED )
# Workaround for the non-working REQUIRED flag
if ( NOT SDL_FOUND )
    message ( FATAL_ERROR "SDL not found!" )
endif ( NOT SDL_FOUND )

link_libraries (
        ${SDL_LIBRARY}
        ${SDLDRAW_LIBRARY}
        ${SDLTTF_LIBRARY} # if using SDL_ttf, obviously
        SDLmain # Sadly not included in SDL_LIBRARY variable
)
set(CMAKE_CXX_STANDARD 17)
#add_executable(ProgOnCPP Lab3/Lab3_1.cpp Lab3/Lab3_1.h Lab3/Lab3_main.cpp tmp/tmp.cpp)
add_executable(ProgOnCPP Lab3/Lab3_1.cpp Lab3/Lab3_1.h Lab3/Lab3_main.cpp)
#add_executable(ProgOnCPP Lab5/Lab5_1.cpp Lab5/lab_5_1_cl.h)
#add_executable(ProgOnCPP Lab5/Lab5_2.cpp Lib/Stack.h)
#add_executable(ProgOnCPP Lab2/lab2_1.cpp)
#add_executable(ProgOnCPP Lab6/Lab6_main.cpp Lab6/str.cpp Lab6/str_id.cpp)