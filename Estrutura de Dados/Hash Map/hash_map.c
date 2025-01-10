#include <stdlib.h>
#include <stdint.h>
#include "./linked_list.c"
#include "./hash.c"

typedef const char *string;



typedef struct HashMap {
    LinkedList *lista; // Lista de LinkedLists
    size_t len;
    size_t max_size;
} HashMap;

HashMap *newHashMap(size_t size) {
    HashMap *map = (HashMap*)malloc(sizeof(HashMap));
    
    return map;
}

void add(HashMap *map, string key, int value) {
    size_t index = hash();
}