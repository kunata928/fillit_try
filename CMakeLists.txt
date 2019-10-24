cmake_minimum_required(VERSION 3.14)
project(fillit C)

set(CMAKE_C_STANDARD 99)

include_directories(libft)

set(SOURCES  main.c)

set (HEADER get_next_line.h)

add_executable(fillit ${SOURCES} ${HEADERS})

add_subdirectory(libft)

target_link_libraries(fillit libft)