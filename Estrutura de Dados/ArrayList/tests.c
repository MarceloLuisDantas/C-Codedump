#include <stdio.h>
#include <string.h>
#include "./arrayList.c"
#include "../../utest.c"


// Teste para verificar se a criação esta funcionando
void test_1() {
    println("===== 1º testes =======================");
    Result list_result_err = newArrayList(-1);
    if (list_result_err.err == "OK") {
        println("Erro ao tentar criar Array List -1");
        return;
    }
    
    Result list_result = newArrayList(10);
    if (list_result.err != "OK") {
        println(list_result.err);
        return;
    }

    ArrayList *list = list_result.value;
    if (list->len != 0) {
        print_erro("Erro recuperar tamanho da lista", 0, list->len);
        return;
    }

    println(" 1º Test - Ok");
}                                                 


// Teste para verificar se a adição de elementos esta funcionado
void test_2() {
    println("===== 2º testes =======================");
    ArrayList *list = newArrayList(2).value;
    const char *err_msg = get(list, 0).err;
    if (strcmp(err_msg, "OK") == 0) {
        println("Erro ao recuperar item em lista vazia");
        return;
    }
    
    const char *err1 = add(list, 10);
    if (strcmp(err1, "OK") != 0) {
        println(strcat("Teste 1 - ", err1));
        return;
    }

    int valor = *((int *)(get(list, 0).value));
    if (valor != 10) {
        print_erro("Erro ao recuperar primeiro index", 10, valor);
        return;
    }
    if (list->len != 1) {
        print_erro("Erro ao alterar o len da lista", 1, list->len);
        return;
    }
    
    const char *err2 = add(list, 20);
    if (strcmp(err2, "OK") != 0) {
        println(strcat("Teste 2 - ", err2));
        return;
    }
    valor = *((int *)(get(list, 1).value));
    if (valor != 20) {
        print_erro("Erro ao recuperar segundo index", 20, valor);
        return;
    }
    if (list->len != 2) {
        print_erro("Erro ao alterar o len da lista", 2, list->len);
        return;
    }

    const char *err3 = add(list, 30);
    if (strcmp(err3, "OK") != 0) {
        println(err3);
        return;
    }
    valor = *((int *)(get(list, 2).value));
    if (valor != 30) {
        print_erro("Erro ao recuperar segundo index", 30, valor);
        return;
    }
    if (list->max_l != 3) {
        print_erro("Erro ao alterar o max_l", 3, list->max_l);
        return;
    }

    println(" 2º Teste - Ok");
}

// Teste para verificar se set esta funcionando
void test_3() {
    println("===== 3º testes =======================");
    ArrayList *list = newArrayList(10).value;
    add(list, 10);
    add(list, 20);
    add(list, 30);
    add(list, 40);
    add(list, 50);

    const char *err_msg = set(list, 10, 8).err;
    if (strcmp(err_msg, "OK") == 0) {
        println("Erro ao tentar setar valor out of bounds");
        return;
    }

    set(list, 25, 1);
    int num = *((int *)(get(list, 1).value));
    if (num != 25) {
        print_erro("Erro ao setar valor valido", 25, num);
        return;
    }

    println(" 3º Teste - Ok");
}

void test_4() {
    println("===== 4º testes =======================");
    ArrayList *list = newArrayList(5).value;
    add(list, 1);
    add(list, 2);
    add(list, 3);
    add(list, 4);
    add(list, 5);

    int esperado1[] = {1, 2, 3, 4, 5};
    int *lista1 = toArray(list).value;
    if (compListas(esperado1, lista1, 5) == 0) {
        println("Listas diferentes");
        print_array_int(esperado1, 5);
        print_array_int(lista1, 5);
    }
    
    add(list, 6);

    int esperado2[] = {1, 2, 3, 4, 5, 6};
    int *lista2 = toArray(list).value;
    if (compListas(esperado2, lista2, 6) == 0) {
        println("Listas diferentes");
        print_array_int(esperado2, 6);
        print_array_int(lista2, 6);
    }

    println(" 4º Teste - OK ");
}

int main() {
    println("===== Rodando testes - Array List =====");
    println("");

    test_1();
    println("");

    test_2();
    println("");

    test_3();
    println("");

    test_4();
    println("");
    
    return 0;
}