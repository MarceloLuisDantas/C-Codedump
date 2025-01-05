#include <stdio.h>
#include "./doubleLinkedList.c"

void print_erro(char label[90], int esperado, int recebido) {
    printf(label);
    printf("        Valor esperado: %d\n", esperado);
    printf("        Valor recebido: %d\n", recebido);
}

// Teste para verificar se addNode e get estão funcionando
void test_1() {
    printf("===== Rodando 1º teste =======================\n");
    List *lista = newList();
    int valor = get(lista, 0);
    if (valor != 0) {
        print_erro("Erro ao resgatar element out of bounds\n", 0, valor);
        return;
    }

    addNode(lista, 10);
    valor = get(lista, 0);
    if (valor != 10) {
        print_erro("Erro ao tentar adicionar ou resgatar elemento\n", 10, valor);
        return;
    }

    addNode(lista, 20);
    valor = get(lista, 1);
    if (valor != 20) {
        print_erro("Erro ao tentar adicionar ou resgatar elemento\n", 20, valor);
        return;
    }

    addNode(lista, 30);
    valor = get(lista, 2);
    if (valor != 30) {
        print_erro("Erro ao tentar adicionar ou resgatar elemento\n", 30, valor);
        return;
    }

    addNode(lista, 40);
    valor = get(lista, 3);
    if (valor != 40) {
        print_erro("Erro ao tentar adicionar ou resgatar elemento\n", 40, valor);
        return;
    }

    valor = get(lista, 1);
    if (valor != 20) {
        print_erro("Erro ao tentar resgatar elemento no meio da lista\n", 20, valor);
        return;
    }

    valor = get(lista, 3);
    if (valor != 40) {
        print_erro("Erro ao tentar resgatar elemento no meio da lista\n", 40, valor);
        return;
    }

    printf("Teste 1 - Ok\n");
}

// Teste para index our of bounds
int test_2_sub_1() {
    List *lista = newList();
    int err = insert(lista, 10, -1);
    if (err == 1) {
        print_erro("Sub Test 1 - Erro ao tentar adicionar elemento em index invalido\n", 1, err);
        return 1;
    }
    err = insert(lista, 10, 10);
    if (err == 1) {
        print_erro("Sub Test 1 - Erro ao tentar adicionar elemento em index invalido\n", 1, err);
        return 1;
    }

    printf("Sub-Test 1 - Ok\n");
    return 0;
}

// Adiciona valor no index 0 com lista vazia
int test_2_sub_2() {
    List *lista = newList();

    int err = insert(lista, 10, 0);
    if (err != 1) {
        print_erro("Sub Test 2 - Erro ao tentar adicionar elemento no index 0\n", 1, err);
        return 1;
    }

    // Verifica se o valor foi adicionado ao index esperado
    int valor = get(lista, 0);
    if (valor != 10) {
        print_erro("Sub Test 2 - Erro ao tentar recuperar apos inserção elemento no index 0\n", 10, valor);
        return 1;
    }

    // Verificar se o valor de start esta correto
    int valorStart = lista->start->valor;
    if (valorStart != 10) {
        print_erro("Sub Test 2 - Erro ao tentar recuperar valor de start apos inserção index 0\n", 10, valorStart);
        return 1;
    }

    // Verificar se o valor de head esta correto
    int valorHead = lista->head->valor;
    if (valorHead != 10) {
        print_erro("Sub Test 2 - Erro ao tentar recuperar valor de head apos inserção index 0\n", valor, valorHead);
        return 1;
    }

    printf("Sub-Test 2 - Ok\n");
    return 0;
}

// Adiciona valor no index 0 com lista não vazia
int test_2_sub_3() {
    List *lista = newList();
    addNode(lista, 20);

    int err = insert(lista, 10, 0);
    if (err != 1) {
        print_erro("Sub Test 3 - Erro ao tentar adicionar elemento no index 0\n", 1, err);
        return 1;
    }

    // Verifica se o valor foi adicionado ao index esperado
    int valor = get(lista, 0);
    if (valor != 10) {
        print_erro("Sub Test 3 - Erro ao tentar recuperar apos inserção elemento no index 0\n", 10, valor);
        return 1;
    }

    // Verificar se o valor de start esta correto
    int valorStart = lista->start->valor;
    if (valorStart != 10) {
        print_erro("Sub Test 3 - Erro ao tentar recuperar valor de start apos inserção index 0\n", 10, valorStart);
        return 1;
    }

    // Verificar se o valor de head esta correto
    int valorHead = lista->head->valor;
    if (valorHead != 20) {
        print_erro("Sub Test 3 - Erro ao tentar recuperar valor de head apos inserção index 0\n", 20, valorHead);
        return 1;
    }

    printf("Sub-Test 3 - Ok\n");
    return 0;
}

// Adicionar valor no final do array com 1 elemento
int test_2_sub_4() {
    List *lista = newList();
    addNode(lista, 10);

    int err = insert(lista, 20, 1);
    if (err != 1) {
        print_erro("Sub Test 4 - Erro ao tentar adicionar elemento no index 1\n", 1, err);
        return 1;
    }

    // Verifica se o valor foi adicionado ao index esperado
    int valor = get(lista, 1);
    if (valor != 20) {
        print_erro("Sub Test 4 - Erro ao tentar recuperar apos inserção elemento no index 1\n", 10, valor);
        return 1;
    }

    // Verificar se o valor de start esta correto
    int valorStart = lista->start->valor;
    if (valorStart != 10) {
        print_erro("Sub Test 4 - Erro ao tentar recuperar valor de start apos inserção index 1\n", 10, valorStart);
        return 1;
    }

    // Verificar se o valor de head esta correto
    int valorHead = lista->head->valor;
    if (valorHead != 20) {
        print_erro("Sub Test 3 - Erro ao tentar recuperar valor de head apos inserção index 1\n", 20, valorHead);
        return 1;
    }

    printf("Sub-Test 4 - Ok\n");
    return 0;
}

/*  Teste para verificar se insert esta funcionando para:
 *  Index invalidos
 *  Index 0 com lista vazia
 *  Index 0 com lista com 1 elemento
 *  Index final com lista com 1 elemento
 */
void test_2() {
    printf("===== Rodando 2º testes ======================\n");
    if (test_2_sub_1() != 0) 
        return;
    
    if (test_2_sub_2() != 0) 
        return;
    
    if (test_2_sub_3() != 0) 
        return;

    if (test_2_sub_4() != 0) 
        return;

    printf("Test 2 - Ok\n");
}

//  Inserção no index 1 em lista de 2 elementos, entra start e o head
//  insert([0] -> [2], E, 1) = [0] -> [E] -> [2]
int test_3_sub_1() {
    List *lista = newList();
    addNode(lista, 0);
    addNode(lista, 2);

    int err = insert(lista, 1, 1);
    if (err != 1) {
        print_erro("Sub-Test 1 - Erro ao tentar inserir no index 1 em lista de 2 valores\n", 1, err);
        return 1;
    }

    int valor = get(lista, 1);
    if (valor != 1) {
        print_erro("Sub-Test 1 - Erro ao recuperar valor apos inserção\n", 1, valor);
        return 1;
    }

    int valorStart = lista->start->valor;
    if (valorStart != 0) {
        print_erro("Sub-Test 1 - Valor de Start foi alterado apos inserção\n", 0, valorStart);
        return 1;
    }

    int valorHead = lista->head->valor;
    if (valorHead != 2) {
        print_erro("Sub-Test 1 - Valor de Start foi alterado apos inserção\n", 2, valorHead);
        return 1;
    }

    printf("Sub-Test 1 - Ok\n");
    return 0;
}

// Inserção do elemento E no index 1 em uma lista de 3 elementos
// insert([0] -> [2] -> [3], E, 1) = [0] -> [E] -> [2] -> [3]
int test_3_sub_2() {
    List *lista = newList();
    addNode(lista, 0);
    addNode(lista, 2);
    addNode(lista, 3);

    int err = insert(lista, 1, 1);
    if (err != 1) {
        print_erro("Sub-Test 2 - Erro ao tentar inserir no index 1 em lista de 3 valores\n", 0, err);
        return 1;
    }

    int valor = get(lista, 1);
    if (valor != 1) {
        print_erro("Sub-Test 2 - Erro ao recuperar valor apos inserção\n", 1, valor);
        return 1;
    }

    int valorStart = lista->start->valor;
    if (valorStart != 0) {
        print_erro("Sub-Test 2 - Valor de Start foi alterado apos inserção\n", 0, valorStart);
        return 1;
    }

    int valorHead = lista->head->valor;
    if (valorHead != 3) {
        print_erro("Sub-Test 2 - Valor de Start foi alterado apos inserção\n", 3, valorHead);
        return 1;
    }

    printf("Sub-Test 2 - Ok\n");
    return 0;
}

// Inserção do elemento E no index 2 em uma lista de 3 elementos
// insert([0] -> [2] -> [3], E, 2) = [0] -> [2] -> [E] -> [3]
int test_3_sub_3() {
    List *lista = newList();
    addNode(lista, 0);
    addNode(lista, 2);
    addNode(lista, 3);

    int err = insert(lista, 1, 2);
    if (err != 1) {
        print_erro("Sub-Test 3 - Erro ao tentar inserir no index 2 em lista de 3 valores\n", 0, err);
        return 1;
    }

    int valor = get(lista, 2);
    if (valor != 1) {
        print_erro("Sub-Test 3 - Erro ao recuperar valor apos inserção\n", 1, valor);
        return 1;
    }

    int valorStart = lista->start->valor;
    if (valorStart != 0) {
        print_erro("Sub-Test 3 - Valor de Start foi alterado apos inserção\n", 0, valorStart);
        return 1;
    }

    int valorHead = lista->head->valor;
    if (valorHead != 3) {
        print_erro("Sub-Test 3 - Valor de Start foi alterado apos inserção\n", 3, valorHead);
        return 1;
    }

    printf("Sub-Test 3 - Ok\n");
    return 0;
}


/*  Teste para verificar inserção esta funcionando para:
 *  Inserção no index 1 em lista de 2 elementos, entra start e o head
 *  insert([0] -> [2], E, 1) = [0] -> [E] -> [2]
 *  
 *  Inserção do elemento E no index 1 em uma lista de 3 elementos
 *  insert([0] -> [2] -> [3], E, 1) = [0] -> [E] -> [2] -> [3]
 *  
 *  Inserção do elemento E no index 2 em uma lista de 3 elementos
 *  insert([0] -> [2] -> [3], E, 2) = [0] -> [2] -> [E] -> [3]
 */
void test_3() {
    printf("===== Rodando 3º testes ======================\n");
    if (test_3_sub_1() != 0) 
        return;
    
    if (test_3_sub_2() != 0) 
        return;
    
    if (test_3_sub_3() != 0) 
        return;

    printf("Test 3 - Ok\n");
}


// Remover index out of bounds
int test_4_sub_1() {
    List *lista = newList();

    int err = delete(lista, 9);
    if (err == 1) {
        print_erro("Sub-Test 4 - Erro ao deletar index out of bounds (9)\n", 1, err);
        return 1;
    }

    err = delete(lista, -2);
    if (err == 1) {
        print_erro("Sub-Test 4 - Erro ao deletar index out of bounds (-2)\n", 1, err);
        return 1;
    }

    addNode(lista, 1);
    err = delete(lista, 1);
    if (err == 1) {
        print_erro("Sub-Test 4 - Erro ao deletar index out of bounds (1)\n", 1, err);
        return 1;
    }

    printf("Subs-Test 1 - Ok\n");
    return 0;
}

// Remover elemento 0 de uma lista de 1 elemento
int test_4_sub_2() {
    List *lista = newList();
    addNode(lista, 10);

    int err = delete(lista, 0);
    if (err != 10) {
        print_erro("Sub-Test 2 - Erro ao deletar o primeiro index de lista com 1 elemento\n", 10, err);
        return 1;
    }

    if (lista->start != NULL) {
        printf("Sub-Test 2 - Node Start era para ser Null apos remoção\n");
        return 1;
    }

    if (lista->head != NULL) {
        printf("Sub-Test 2 - Node Head era para ser Null apos remoção\n");
        return 1;
    }

    printf("Subs-Test 2 - Ok\n");
    return 0;
}

// Remover elemento 0 de uma lista de 2 elementos
int test_4_sub_3() {
    List *lista = newList();
    addNode(lista, 10);
    addNode(lista, 20);

    int err = delete(lista, 0);
    if (err != 10) {
        print_erro("Sub-Test 3 - Erro ao deletar o primeiro index de lista com 2 elemento\n", 10, err);
        return 1;
    }

    int valorStart = lista->start->valor;
    if (valorStart != 20) {
        print_erro("Sub-Test 3 - Valor de Start deveria ser o valor do segundo addNode\n", 20, valorStart);
        return 1;
    }

    int valorHead = lista->head->valor;
    if (valorHead != 20) {
        print_erro("Sub-Test 3 - Valor de Head não deveria ter sido alterado\n", 20, valorHead);
        return 1;
    }

    printf("Subs-Test 3 - Ok\n");
    return 0;
}

// Remover elemento 1 de uma lista de 2 elementos
int test_4_sub_4() {
    List *lista = newList();
    addNode(lista, 10);
    addNode(lista, 20);

    int valor = delete(lista, 1);
    if (valor != 20) {
        print_erro("Sub-Test 4 - Erro ao deletar o ultimo index de lista com 2 elemento\n", 20, valor);
        return 1;
    }

    int valorStart = lista->start->valor;
    if (valorStart != 10) {
        print_erro("Sub-Test 4 - Valor de Start não deveria ser alterado\n", 10, valorStart);
        return 1;
    }

    int valorHead = lista->head->valor;
    if (valorHead != 10) {
        print_erro("Sub-Test 4 - Valor de Head deveria ser o valor do primeiro addNode\n", 10, valorHead);
        return 1;
    }

    printf("Subs-Test 4 - Ok\n");
    return 0;
}

/*  Testes para verificar delete esta funcionando para:
 *  Remover index out of bounds
 *  Remover elemento 0 de uma lista de 1 elemento
 *  Remover elemento 0 de uma lista de 2 elementos
 *  Remover elemento 1 de uma lista de 2 elementos
 */
void test_4() {
    printf("===== Rodando 4º testes ======================\n");
    if (test_4_sub_1() != 0) 
        return;
    
    if (test_4_sub_2() != 0) 
        return;
    
    if (test_4_sub_3() != 0) 
        return;
    
    if (test_4_sub_4() != 0) 
        return;

    printf("Test 4 - Ok\n");
}

// Remover o index 1 de uma lista de 3 valores
int test_5_sub_1() {
    List *lista = newList();
    addNode(lista, 10);
    addNode(lista, 20);
    addNode(lista, 30);

    int valor = delete(lista, 1);
    if (valor != 20) {
        print_erro("Sub-Test 1 - Erro a tentar remover o index 1\n", 20, valor);
        return 1;
    }

    int valorStart = lista->start->valor;
    if (valorStart != 10) {
        print_erro("Sub-Test 1 - O valor de Start n deveria ser alterado\n", 10, valorStart);
        return 1;
    }

    int valorHead = lista->head->valor;
    if (valorHead != 30) {
        print_erro("Sub-Test 1 - O valor de Head n deveria ser alterado\n", 30, valorHead);
        return 1;
    }

    printf("Sub-Test 1 - Ok\n");
    return 0;
}

// Remover o index 1 de uma lsita de 4 valores
int test_5_sub_2() {
    List *lista = newList();
    addNode(lista, 10);
    addNode(lista, 20);
    addNode(lista, 30);
    addNode(lista, 40);

    int valor = delete(lista, 1);
    if (valor != 20) {
        print_erro("Sub-Test 2 - Erro a tentar remover o index 1\n", 20, valor);
        return 1;
    }

    int valorStart = lista->start->valor;
    if (valorStart != 10) {
        print_erro("Sub-Test 2 - O valor de Start n deveria ser alterado\n", 10, valorStart);
        return 1;
    }

    int valorHead = lista->head->valor;
    if (valorHead != 40) {
        print_erro("Sub-Test 2 - O valor de Head n deveria ser alterado\n", 30, valorHead);
        return 1;
    }

    printf("Sub-Test 2 - Ok\n");
    return 0;
}

// Remover o index 2 de uma lista de 4 valores
int test_5_sub_3() {
    List *lista = newList();
    addNode(lista, 10);
    addNode(lista, 20);
    addNode(lista, 30);
    addNode(lista, 40);

    int valor = delete(lista, 2);
    if (valor != 30) {
        print_erro("Sub-Test 3 - Erro a tentar remover o index 2\n", 30, valor);
        return 1;
    }

    int valorStart = lista->start->valor;
    if (valorStart != 10) {
        print_erro("Sub-Test 3 - O valor de Start n deveria ser alterado\n", 10, valorStart);
        return 1;
    }

    int valorHead = lista->head->valor;
    if (valorHead != 40) {
        print_erro("Sub-Test 3 - O valor de Head n deveria ser alterado\n", 40, valorHead);
        return 1;
    }

    printf("Sub-Test 3 - Ok\n");
    return 0;
}

/* Teste para verificar se delete esta funcionado para:
 * Remover o index 1 de uma lista de 3 valores
 * Remover o index 1 de uma lsita de 4 valores
 * Remover o index 2 de uma lista de 4 valores
 */
void test_5() {
    printf("===== Rodando 5º testes ======================\n");
    if (test_5_sub_1() != 0) 
        return;
    
    if (test_5_sub_2() != 0) 
        return;
    
    if (test_5_sub_3() != 0) 
        return;
    
    printf("Test 5 - Ok\n");
    return 0;
}

int compListas(int *lista1, int *lista2, int len) {
    for (int i = 0; i < len; i++) {
        int v1 = lista1[i];
        int v2 = lista2[i];
        // printf("Valor Lista 1 - %d\n", v1);
        // printf("Valor Lista 2 - %d\n", v2);
        if (v2 != v2) 
            return 0;
    }
        
    return 1;
}

// Teste para verificar se toArray esta funcionando
void test_6() {
    printf("===== Rodando 5º testes ======================\n");
    List *lista = newList();
    addNode(lista, 1);
    addNode(lista, 2);
    addNode(lista, 3);
    addNode(lista, 4);
    addNode(lista, 5);
    
    // t1 ----------
    int esperada[] = {1, 2, 3, 4, 5};
    int *array = toArray(lista);
    if (compListas(esperada, array, 5) == 0) {
        printf("Erro, lista recebido é diferente do esperado\n");
        return;
    }

    // t2 ----------
    insert(lista, 0, 0);
    int esperada2[] = {0, 1, 2, 3, 4, 5};
    int *array2 = toArray(lista);
    if (compListas(esperada2, array2, 6) == 0) {
        printf("Erro, lista recebido é diferente do esperado\n");
        return;
    }

    // t3 ----------
    int err = insert(lista, 6, 6);
    if (err == 0) {
        printf("Index invalido");
        return;
    }

    int esperada3[] = {0, 1, 2, 3, 4, 5, 6};
    int *array3 = toArray(lista);
    if (compListas(esperada3, array3, 7) == 0) {
        printf("Erro, lista recebido é diferente do esperado\n");
        return;
    }

    // t4 ----------
    int err2 = delete(lista, 3);
    if (err2 == 0) {
        printf("Index invalido");
        return;
    }

    int esperada4[] = {0, 1, 2, 4, 5, 6};
    int *array4 = toArray(lista);
    if (compListas(esperada4, array4, 6) == 0) {
        printf("Erro, lista recebido é diferente do esperado\n");
        return;
    }

    // t5 ----------
    int err3 = insert(lista, 3, 3);
    if (err3 == 0) {
        printf("Index invalido");
        return;
    }

    int esperada5[] = {0, 1, 2, 3, 4, 5, 6};
    int *array5 = toArray(lista);
    if (compListas(esperada5, array5, 7) == 0) {
        printf("Erro, lista recebido é diferente do esperado\n");
        return;
    }

    // t6 ----------
    delete(lista, 0);

    int esperada7[] = {1, 2, 3, 4, 5, 6};
    int *array7 = toArray(lista);
    if (compListas(esperada7, array7, 6) == 0) {
        printf("Erro, lista recebido é diferente do esperado\n");
        return;
    }

    // t7 ----------
    int err5 = delete(lista, 5);
    if (err5 == 0) {
        printf("Index invalido");
        return;
    }

    int esperada8[] = {1, 2, 3, 4, 5};
    int *array8 = toArray(lista);
    if (compListas(esperada8, array8, 5) == 0) {
        printf("Erro, lista recebido é diferente do esperado\n");
        return;
    }

    printf("Test 6 - Ok");
}

int main() {
    printf("===== Rodando testes - Double Linked List ====\n");
    
    printf("\n");
    test_1();
    
    printf("\n");
    test_2();

    printf("\n");
    test_3();

    printf("\n");
    test_4();

    printf("\n");
    test_5();

    printf("\n");
    test_6();

    return 0;
}