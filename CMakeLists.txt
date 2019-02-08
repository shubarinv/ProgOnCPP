cmake_minimum_required(VERSION 3.13)
project(ProgOnCPP)

find_package(SDL REQUIRED)
find_package ( SDL_ttf REQUIRED )
# Workaround for the non-working REQUIRED flag
if ( NOT SDL_FOUND )
    message ( FATAL_ERROR "SDL not found!" )
endif ( NOT SDL_FOUND )

link_libraries (
        ${SDL_LIBRARY}
        ${SDLTTF_LIBRARY} # if using SDL_ttf, obviously
        SDLmain # Sadly not included in SDL_LIBRARY variable
)
set(CMAKE_CXX_STANDARD 14)
add_executable(ProgOnCPP Lab1/main.cpp)
#target_link_libraries(ProgOnCPP /usr/lib/SDL.h)