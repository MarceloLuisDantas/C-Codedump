cmake_minimum_required(VERSION 3.22.1)
project("STRINGS")
add_compile_options(-Wall -Werror -g)

include(CTest)
enable_testing()

add_executable(
    StringTests
    tests/tests.c
    src/Strings.c
)