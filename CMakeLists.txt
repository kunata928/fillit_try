cmake_minimum_required(VERSION 3.14)
project(fillit C)

set(CMAKE_C_STANDARD 99)

include_directories(libft/includes)

set(SOURCES srcs/main.c srcs/parsing.c srcs/print.c srcs/solve.c)

set(HEADERS includes/fillit.h)

add_executable(fillit ${SOURCES} ${HEADERS})

add_subdirectory(libft)

target_link_libraries(fillit libft)