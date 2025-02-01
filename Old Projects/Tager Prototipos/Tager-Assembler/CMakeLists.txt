cmake_minimum_required(VERSION 3.22.1)
project("TAGER_ASSEMBLER")
add_compile_options(-Wall -g)
add_executable(
    Tager
    src/Tager.c
    src/Files/Files.c
    src/Linked\ List/linked_list.c
    src/Linked\ List/labels_list.c
    src/Strings/Strings.c
    src/Sintaxes/sintaxes.c
)
target_link_libraries(Tager PUBLIC m)
