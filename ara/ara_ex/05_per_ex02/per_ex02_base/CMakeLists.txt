cmake_minimum_required(VERSION 3.4)

include(GNUInstallDirs)

project(PER_EX02)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

# Global compiler flags
add_compile_options( -pedantic -Wall -Wextra -Wnon-virtual-dtor
                    -Wconversion -Wold-style-cast "$<$<CONFIG:Debug>:-ggdb3;-Og>"
)

#machine envs.
set(MACHINE_NAME "Machine_ECU")
set(MACHINE_DESIGN_NAME "Machine_ECU")
string(TOLOWER ${MACHINE_NAME} MACHINE_NAME_LOWER)

add_subdirectory(PerExampleKvs)
