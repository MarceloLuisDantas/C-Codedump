cmake_minimum_required(VERSION 3.22.1)
project(TESTE)

add_compile_options(-Wall -Werror)

set(LIBRARY_DIR "${CMAKE_SOURCE_DIR}/libs")

# add_executable(
#     ListTest
#     ListTest.c
#     src/LinkedList.c
# )

# Include the libs directory for header files (Strings.h)
include_directories(${LIBRARY_DIR})

# Add the shared library target for LinkedList
add_library(LinkedList SHARED src/LinkedList.c)

# Specify the directory where libStrings.so is located
target_link_directories(LinkedList PRIVATE ${LIBRARY_DIR})

# Link libStrings.so to the LinkedList shared library
target_link_libraries(LinkedList PRIVATE Strings)

# Set the output directory for the shared library (optional)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# # Specify the include directory for Strings.h
# target_include_directories(ListTest PUBLIC ${LIBRARY_DIR})

# # Specify the library directory
# target_link_directories(ListTest PUBLIC ${LIBRARY_DIR})

# # Link the library explicitly using its full path
# target_link_libraries(ListTest PUBLIC ${LIBRARY_DIR}/libStrings.so)

#===============================================================

