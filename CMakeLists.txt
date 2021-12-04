cmake_minimum_required(VERSION 3.20)
project(GNL C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra -Werror -D BUFFER_SIZE=42)
add_executable(GNL main.c get_next_line.c get_next_line.h get_next_line_utils.c)
