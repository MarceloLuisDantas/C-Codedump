#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.c"

int main() {
    LinkedList *linhas = newLinkedList();

    FILE *fp = fopen("arquivo.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[read - 1] == '\n') 
            read -= 1;

        // Criando uma copia do valor na heap
        char *valorNaHeap = (char *)malloc(sizeof(char) * read);
        memmove(valorNaHeap, line, read);

        add(linhas, valorNaHeap, read);
    }

    fclose(fp);
    if (line)
        free(line);
    
    char **linhas_m = toArray(linhas);
    for (int i = 0; i < linhas->len; i++)
        printf("%s\n", linhas_m[i]);

    FILE *out = fopen("output.txt", "w");
    for (int i = 0; i < linhas->len; i++)
        fprintf(out, "%s\n", linhas_m[i]);

    return 0;
}