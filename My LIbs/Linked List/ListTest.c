#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "./src/LinkedList.h"

#define TRUE 1
#define FALSE 0

int runTest(int (*test)(), int number, const char *test_name) {
    printf("Running test %d - %s\n", number, test_name);
    int result = test();
    if (result == FALSE) {
        printf("Teste %d - %s, DO NOT PASS\n\n", number, test_name);
        return FALSE;
    }
    printf("Teste %d - %s, PASS\n\n", number, test_name);
    return TRUE;
}

// ============================================
// ================== TESTES ==================
// ============================================

int test_create_ll() {
    LinkedList *ll = newLinkedList();
    if (ll->len != 0) {
        printf("LinkedList len should be 0\n");
        printf("get: %d\n", ll->len);
        return FALSE;
    }

    if (ll->start != NULL) {
        printf("LinkedList start should be NULL\n");
        return FALSE;
    }

    return TRUE;
}

int test_add_element() {
    LinkedList *ll = newLinkedList();
    add(ll, " ");
    if (ll->len != 0) {
        printf("Empty Strings shouldn't be added to the list\n");
        return FALSE;
    }
    
    add(ll, "teste");
    if (ll->len != 1) {
        printf("Len should be 1\n");
        printf("gets: %d\n", ll->len);
        return FALSE;
    }

    if (StringCmp(ll->start->value, CStringToString("teste")) != TRUE) {
        printf("Strat should be \"teste\"\n");
        printf("gets %s\n", ll->start->value->array);
        return FALSE;
    }

    add(ll, "teste2");
    add(ll, "teste3");
    if (ll->len != 3) {
        printf("Len should be 3\n");
        printf("gets: %d\n", ll->len);
        return FALSE;
    }

    if (StringCmp(ll->start->next->next->value, CStringToString("teste3")) != TRUE) {
        printf("Strat should be \"teste\"\n");
        printf("gets %s\n", ll->start->value->array);
        return FALSE;
    }

    return TRUE;
}

int test_get_element() {
    LinkedList *ll = newLinkedList();
    String *sn = getValue(ll, 0);
    if (sn != NULL) {
        printf("String should be NULL\n");
        return FALSE;
    }

    add(ll, "teste0");
    add(ll, "teste1");
    add(ll, "teste2");
    add(ll, "teste3");

    String *sn2 = getValue(ll, 4);
    if (sn2 != NULL) {
        printf("String should be NULL\n");
        return FALSE;
    }

    String *s = getValue(ll, 3);
    if (StringCmp(s, CStringToString("teste3")) != TRUE) {
        printf("String should be \"teste3\"\n");
        printf("get %s", s->array);
        return FALSE;
    }

    return TRUE;
}


int test_set_element() {
    LinkedList *ll = newLinkedList();
    int r = set(ll, "teste1.2", 0);
    if (r != 1) {
        printf("Should be out of bounds");
        return FALSE;
    }
    
    add(ll, "teste0");
    add(ll, "teste1");
    add(ll, "teste2");
    add(ll, "teste3");
    add(ll, "teste4");

    int r2 = set(ll, "teste1.2", 5);
    if (r2 != 1) {
        printf("Should be out of bounds");
        return FALSE;
    }

    int result = set(ll, "teste0.2", 0);
    if (result != 0) {
        printf("Should be 0");
        return FALSE;
    }

    String *s = getValue(ll, 0);
    if (StringCmp(s, CStringToString("teste0.2")) != TRUE) {
        printf("Unespected value to the String\n");
        printf("Expeted: \"teste0.2\"\n");
        printf("Get: \"%s\"\n", s->array);
        return FALSE;
    }

    set(ll, "teste0.3", 0);
    String *s2 = getValue(ll, 0);
    if (StringCmp(s2, CStringToString("teste0.3")) != TRUE) {
        printf("Unespected value to the String\n");
        printf("Expeted: \"teste0.3\"\n");
        printf("Get: \"%s\"\n", s2->array);
        return FALSE;
    }

    set(ll, "teste4.2", 4);
    String *s3 = getValue(ll, 4);
    if (StringCmp(s3, CStringToString("teste4.2")) != TRUE) {
        printf("Unespected value to the String\n");
        printf("Expeted: \"teste4.2\"\n");
        printf("Get: \"%s\"\n", s3->array);
        return FALSE;
    }

    return TRUE;
}

int test_delete_element() {
    LinkedList *ll = newLinkedList();
    int r1 = delete(ll, 0);
    if (r1 != 1) {
        printf("r1 should be 1\n");
        return FALSE;
    }

    add(ll, "teste0");
    delete(ll, 0);
    if (ll->len != 0) {
        printf("Len should be 0\n");
        return FALSE;
    }
    if (ll->start != NULL) {
        printf("Start should be NULL\n");
        return FALSE;
    }

    add(ll, "teste0");
    add(ll, "teste1");
    add(ll, "teste2");
    add(ll, "teste3");
    add(ll, "teste4");
    delete(ll, 2);
    if (ll->len != 4) {
        printf("Len should be 4\n");
        return FALSE;
    }
    String *v = getValue(ll, 2);
    if (StringCmp(v, CStringToString("teste3")) != TRUE) {
        printf("String index 2 should be \"teste3\"\n");
        printf("Get: %s\n", v->array);
        return FALSE;
    }

    delete(ll, 3);
    String *vnull = getValue(ll, 3);
    if (vnull != NULL) {
        printf("String index 3 should be NULL after delete\n");
        printf("Get: %s\n", vnull->array);
        return FALSE;
    }
    return TRUE;
}

int test_insert_element() {
    LinkedList *ll = newLinkedList();
    int r = insert(ll, "teste", 1);
    if (r != 1) {
        printf("R should be 1\n");
        return FALSE;
    }

    insert(ll, "teste 0", 0);
    String *s = getValue(ll, 0);
    if (StringCmp(s, CStringToString("teste 0")) != TRUE) {
        printf("S1 should be \"teste -1\"\n");
        printf("S1: %s\n", s->array);
        return FALSE;
    }

    add(ll, "teste 1");
    add(ll, "teste 2");

    insert(ll, "teste -1", 0);
    if (ll->len != 4) {
        printf("Len should be 4\n");
        printf("len: %d", ll->len);
        return FALSE;
    }
    String *s1 = getValue(ll, 0);
    if (StringCmp(s1, CStringToString("teste -1")) != TRUE) {
        printf("S1 should be \"teste -1\"\n");
        printf("S1: %s\n", s1->array);
        return FALSE;
    }

    insert(ll, "teste 3", 4);
    String *s2 = getValue(ll, 4);
    if (StringCmp(s2, CStringToString("teste 3")) != TRUE) {
        printf("S2 should be \"teste 3\"\n");
        printf("S2: %s\n", s2->array);
        return FALSE;
    }

    insert(ll, "teste 2.5", 4);
    String *s3 = getValue(ll, 4);
    if (StringCmp(s3, CStringToString("teste 2.5")) != TRUE) {
        printf("S3 should be \"teste 2.5\"\n");
        printf("S3: %s\n", s3->array);
        return FALSE;
    }

    return TRUE;
}

int test_to_array() {
    LinkedList *l = newLinkedList();

    add(l, "teste 0");
    add(l, "teste 1");
    add(l, "teste 2");
    add(l, "teste 3");

    ArrayString *as = toArray(l);
    for (int i = 0; i < as->len; i++)
        printf("%d - %s\n", i, as->array[i]->array);
    
    return TRUE;
}

int main() {
    printf("==================== RUNNING TESTES ====================\n");
    runTest(&test_create_ll, 1, "Create Linked List Test");
    runTest(&test_add_element, 2, "Add elements Test");
    runTest(&test_get_element, 3, "Get element Test");
    runTest(&test_set_element, 4, "Set element Test");
    runTest(&test_delete_element, 5, "Delete element Test");
    runTest(&test_insert_element, 6, "Insert element Test");
    runTest(&test_to_array, 7, "To ArrayString Test");

    return 0;
}
