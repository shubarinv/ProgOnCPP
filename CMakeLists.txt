cmake_minimum_required(VERSION 3.10.2)
project(ProgOnCPP)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/ ${CMAKE_MODULE_PATH})
#find_package(SDL REQUIRED)
#find_package ( SDL_ttf REQUIRED )
#find_package ( SDL_draw REQUIRED )
# Workaround for the non-working REQUIRED flag
#if ( NOT SDL_FOUND )
#    message ( FATAL_ERROR "SDL not found!" )
#endif ( NOT SDL_FOUND )

#link_libraries (
 #       ${SDL_LIBRARY}
  #      ${SDLDRAW_LIBRARY}
   #     ${SDLTTF_LIBRARY} # if using SDL_ttf, obviously
    #    SDLmain # Sadly not included in SDL_LIBRARY variable
#)
set(CMAKE_CXX_STANDARD 17)
#add_executable(ProgOnCPP Lab3/Lab3_1.cpp Lab3/Lab3_1.h Lab3/Lab3_main.cpp tmp/tmp.cpp)
#add_executable(ProgOnCPP Lab3/Lab3_1.cpp Lab3/Lab3_1.h Lab3/Lab3_main.cpp)
#add_executable(ProgOnCPP Lab5/Lab5_1.cpp Lab5/lab_5_1_cl.h)
add_executable(ProgOnCPP Lib/Stack.h Lab5/lab5_2N.cpp)
#add_executable(ProgOnCPP Lab2/lab2_1.cpp)
#add_executable(ProgOnCPP Lab6/l_str.h Lab6/l_str_id.h Lab6/l_str_compl.h Lab6/Lab6_Driver.cpp)
