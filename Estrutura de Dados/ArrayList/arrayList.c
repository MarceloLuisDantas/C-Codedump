#include <stdlib.h>
#include <string.h>

typedef struct ArrayList {
    int *list;
    int max_l;
    int len;
} ArrayList;

typedef struct Result {
    const char *err;
    void *value;
} Result;

Result newResult() {
    Result r;
    r.err = "OK";
    r.value = NULL;
    return r;
}

/*  Aloca uma nova ArrayList e retorna um Result com o ponteiro 
 *  para a lista, e uma possivel msg de erro. 
 *  Verifique se result.err != "OK" para verificar erros.
 */
Result newArrayList(int size) {
    Result result = newResult();

    int *list = (int *)malloc(sizeof(int) * size);
    if (list == NULL) {
        // strcopy(result.err, "Erro ao alocar memoria para o array inicial");
        result.err = "Erro ao alocar memoria para o array inicial";
        return result;
    }

    ArrayList *AL = (ArrayList *)malloc(sizeof(ArrayList));
    if (AL == NULL) {
        // strcopy(result.err, "Erro ao alocar memoria para ArrayList");
        result.err = "Erro ao alocar memoria para ArrayList";
        return result;
    }
    AL->list = list;
    AL->max_l = size;
    AL->len = 0;

    result.value = (void *)AL;
    return result;
}

/*  Adiciona o elemento passado ao array, caso o array atinja o
 *  limite de sua capacidade, um novo array sera alocado com 1.5 
 *  do tamanho anterior.
 *  Retorna uma string contendo um erro, ou OK caso não ocorra erros
 */
const char *add(ArrayList *list, int value) {
    // Array cheio, criando um novo array
    if (list->len >= list->max_l) {
        int newMaxLen = list->max_l * 1.5;
        int *newArray = malloc(sizeof(int) * newMaxLen);
        if (newArray == NULL) 
            return "Erro ao tentar alocar o novo array";
        
        memcpy(newArray, list->list, list->max_l);
        free(list->list);
        list->list = newArray;
        list->max_l = newMaxLen;
    }

    list->list[list->len] = value;
    list->len += 1;
    return "OK";
}

/*  Retorna um result contendo o valor do index.
 *  Verifique se result.err != "OK" para erros.
 */
Result get(ArrayList *list, int index) {
    Result result = newResult();
    if (index >= list->len) {
        result.err = "Index out of Bounds";
        return result;
    }
    result.value = &list->list[index];
    return result;
}

/*  Retorna um result contendo uma possivel msg de erro.
 *  Verifique se result.err != "OK" para erros.
 */
Result set(ArrayList *list, int value, int index) {
    Result result = newResult();
    if (index >= list->len) {
        result.err = "Index our of Bounds";
        return result;
    }

    list->list[index] = value;
    return result;
}

Result toArray(ArrayList *list) {
    Result result = newResult();
    int *array = malloc(sizeof(int) * list->len);
    if (array == NULL) {
        result.err = "Não foi possivel alocar o array";
        return result;
    }

    for (int i = 0; i < list->len; i++) 
        array[i] = list->list[i];

    result.value = array;
    return result;
}