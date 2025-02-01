cmake_minimum_required(VERSION 3.22.1)
project("ROY_LIB")
add_compile_options(-Wall)
add_executable(
    roy
    src/roy.c
    src/file.c
    src/linked_list.c
)