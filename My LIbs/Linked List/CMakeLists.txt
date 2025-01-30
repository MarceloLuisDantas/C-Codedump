cmake_minimum_required(VERSION 3.22.1)
project(TESTE)

add_compile_options(-Wall -Werror)

set(LIBRARY_DIR "${CMAKE_SOURCE_DIR}/libs")

add_executable(
    ListTest
    ListTest.c
    src/LinkedList.c
)

# Specify the include directory for Strings.h
target_include_directories(ListTest PRIVATE ${LIBRARY_DIR})

# Specify the library directory
target_link_directories(ListTest PRIVATE ${LIBRARY_DIR})

# Link the library explicitly using its full path
target_link_libraries(ListTest PRIVATE ${LIBRARY_DIR}/libStrings.so)