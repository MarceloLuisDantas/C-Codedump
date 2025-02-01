cmake_minimum_required(VERSION 3.22.1)
project("Tager Assembler")
add_compile_options(-Wall)
add_executable(
    tager
    src/tager.c
    src/file.c
    src/linked_list.c
    src/format_line.c
)