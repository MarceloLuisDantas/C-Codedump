cmake_minimum_required(VERSION 3.22.1)
project(TESTE)

add_compile_options(-Wall)

add_executable(
    main 
    src/main.c 
    src/teste.c
)
