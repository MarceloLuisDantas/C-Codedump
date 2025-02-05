cmake_minimum_required(VERSION 3.22.1)
project(FILES)

add_compile_options(-Wall -Werror)

set(LIBRARY_DIR "${CMAKE_SOURCE_DIR}/libs")
include_directories(${LIBRARY_DIR})

# # Add your executable or library target
# add_executable(
#     TestFiles 
#     tests/tests.c
#     src/Files.c
# )

# Include the libs directory for header files (Strings.h)
include_directories(${LIBRARY_DIR})

# Add the shared library target for LinkedList
add_library(Files SHARED src/Files.c)

# Specify the directory where libStrings.so is located
target_link_directories(Files PRIVATE ${LIBRARY_DIR})

# Link libStrings.so 
target_link_libraries(Files PRIVATE Strings)
target_link_libraries(Files PRIVATE LinkedList)


