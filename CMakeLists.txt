cmake_minimum_required(VERSION 3.21)
project(app2)

set(CMAKE_C_STANDARD 99)

add_executable(app2 header.h main.c read_file.c menu.c funciones.c)
