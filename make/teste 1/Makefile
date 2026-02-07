FLAGS = -Wall -Wextra -Wall
CC = gcc

hello: main.o 
	@echo "Linkando builds/hello"
	$(CC) $(FLAGS) cache/main.o -o builds/hello

main.o: src/main.c
	@echo "Compilando src/main.c"
	$(CC) $(FLAGS) -c src/main.c -o cache/main.o

clean:
	rm cache/*
	rm builds/*

run: hello
	@./builds/hello