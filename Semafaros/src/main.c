/* Objetivo: Aprender a criar e utilizar semafaros
 * Funcionalidade do Programa: Ler todos os 10 arquivos com 10 mil numeros elatorios, 
 * e somar todos os valores em uma variavel global protegida por um semaforo. A primeira 
 * versão sera feita com os semaforos padrão da glibc, apos o programa estar funcionando, 
 * uma nova versão sera feita utilizando semaforos feitos do zero.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

long TOTAL = 0;

void load_file(char *path, char **content) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Erro ao carregar aquivo: %s\n", path);
        exit(1);
    }
    
    fseek(file, 0, SEEK_END);
    long file_len = ftell(file);
    rewind(file);

    *content = malloc(sizeof(char) * (file_len+1));
    fread(*content, 1, file_len, file);
    (*content)[file_len] = '\0';
}

void *count(void *args) {
    struct timespec t;
    t.tv_nsec = 1;
    t.tv_sec = 0;

    // Carrega o arquivo
    char *file_name = args;
    char *file;
    load_file(file_name, &file);

    // le todos os numeros
    long f_total = 0;
    int count = 0;
    
    char *str_num = malloc(sizeof(char) * 4);
    long start = 0;
    long final = 0;
    for (;;) {
        if (file[final] == ' ') {
            strncpy(str_num, (file + start), final - start);
            start = final + 1;
            str_num[final - start] = '\0';
            f_total += atoi(str_num);
            count += 1;
        }
        if (file[start] == '\0') {
            break;
        }
        final += 1;
    }

    
    long local_total_copy = TOTAL;
    printf("Total em \"%s\" = %li\n", file_name, f_total);
    nanosleep(&t, NULL); // delay simulado
    local_total_copy += f_total;
    TOTAL = local_total_copy;
    return 0;
}

int main() {
    // Cria as threads
    pthread_t threads[10];
    for (int i = 1; i < 11; i++) {
        char file_path[17];
        snprintf(file_path, 17, "./src/file%i.txt", i);

        char *copia = malloc(strlen(file_path) + 1);
        strcpy(copia, file_path);
        pthread_create(&threads[i-1], NULL, count, copia);
    }

    // Inicializa as threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Total nos 10 arquivos = %li\n", TOTAL);
    return 0;
}