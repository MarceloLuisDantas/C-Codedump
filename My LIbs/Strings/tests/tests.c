#include <stdio.h>
#include "../src/Strings.h"

#define TRUE 1
#define FALSE 0

int runTest(int (*test)(), int number, const char *test_name) {
    printf("Running test %d - %s\n", number, test_name);
    int result = test();
    if (result == FALSE) {
        printf("Teste %d - %s, DO NOT PASS\n", number, test_name);
        return FALSE;
    }
    printf("Teste %d - %s, PASS\n", number, test_name);
    return TRUE;
}

int charcmp(char c1, char c2) {
    if (c1 == c2) 
        return TRUE;
    return FALSE;
}

// ===============================================
// =========== STRING FUNCTIONS TESTES =========== 
// ===============================================

int cstring_to_string() {
    char *s = "teste";
    String *ms = CStringToString(s);
    for (int i = 0; i < ms->len; i++)
        if (charcmp(ms->array[i], s[i]) == FALSE) {
            printf("Unespected char value\n");
            printf("Expected '%c'\n", s[i]);
            printf("Received '%c'\n", ms->array[i]);
            return FALSE;
        }

    String *empty_s = CStringToString("");
    if (empty_s->array != NULL) {
        printf("Empty array should be a NULL pointer\n");
        return FALSE;
    }

    if (empty_s->len != 0) {
        printf("Unespected len for a empty String\n");
        return FALSE;
    }

    return TRUE; 
}

int StringCMP() {
    String *string1 = CStringToString("Teste");
    String *string2 = CStringToString("Teste");
    if (StringCmp(string1, string2) != TRUE) {
        printf("Strings are not the same\n");
        return FALSE;
    }

    String *string3 = CStringToString("Teste");
    String *string4 = CStringToString("este");
    if (StringCmp(string3, string4) != FALSE) {
        printf("Strings are the same\n");
        return FALSE;
    }

    String *empty_s1 = CStringToString("");
    String *empty_s2 = CStringToString("");
    if (StringCmp(empty_s1, empty_s2) != TRUE) {
        printf("Strings are not the same\n");
        return FALSE;
    }

    return TRUE;
}

int slice() {
    String *string = CStringToString("Teste");
    String *SSlice = getSlice(string, 0, 4);
    if (StringCmp(string, SSlice) != TRUE) {
        printf("Strings are not the same\n");
        return FALSE;
    }

    String *SSlice2 = getSlice(string, 0, 0);
    if (SSlice2->array[0] != 'T') {
        printf("Unespected char value\n");
        printf("Expected 'T'\n");
        printf("Received '%c'\n", SSlice2->array[0]);
        return FALSE;
    }

    if (SSlice2->len != 1) {
        printf("Unespected len value\n");
        printf("Expected 1\n");
        printf("Received '%ld'\n", SSlice2->len);
        return FALSE;
    }

    String *SSlice3 = getSlice(string, 5, 2);
    if (SSlice3 != NULL) {
        printf("String 3 should be NULL\n");
        return FALSE;
    }

    String *SSlice4 = getSlice(string, 8, 22);
    if (SSlice4 != NULL) {
        printf("String 4 should be NULL\n");
        return FALSE;
    }

    return TRUE;
}

// ===============================================
// ======== STRING ARRAY FUNCTIONS TESTES ======== 
// ===============================================

int create_array_string() {
    ArrayString *null_as = newArrayString(0);
    if (null_as != NULL) {
        printf("Array with 0 elements should be NULL\n");
        return FALSE;
    }

    ArrayString *as = newArrayString(10);
    if (as->capacity != 10) {
        printf("Unespected capacity value\n");
        printf("Expected 10\n");
        printf("Received '%ld'\n", as->capacity);
        return FALSE;
    }

    if (as->len != 0) {
        printf("Unespected len value\n");
        printf("Expected 0\n");
        printf("Received '%ld'\n", as->len);
        return FALSE;
    }

    return TRUE;
} 

int push() {
    ArrayString *as = newArrayString(2);
    String *s = CStringToString("TESTE");
    ASPush(as, s);

    if (as->len != 1) {
        printf("Unespected len value\n");
        printf("Expected 1\n");
        printf("Received '%ld'\n", as->len);
        return FALSE;
    }

    if (StringCmp(s, as->array[0]) != TRUE) {
        printf("Unespected String Value\n");
        printf("Expected \"TESTE\"\n");
        printf("Received \"%s\"\n", as->array[0]->array);
        return FALSE;
    }

    return TRUE;
}

int array_to_string() {
    ArrayString *as = newArrayString(3);
    String *snull = arrayToString(as);
    if (snull != NULL) {
        printf("String from empty Array should by NULL\n");
        return FALSE;
    }

    ASPush(as, CStringToString("foo"));
    ASPush(as, CStringToString("bar"));
    String *string = arrayToString(as);
    if (StringCmp(string, CStringToString("foo bar")) != TRUE) {
        printf("Unespected String Value\n");
        printf("Expected \"foo bar\"\n");
        printf("Received \"%s\"\n", string->array);
        return FALSE;
    }

    ASPush(as, CStringToString("test"));
    String *string2 = arrayToString(as);
    if (StringCmp(string2, CStringToString("foo bar test")) != TRUE) {
        printf("Unespected String Value\n");
        printf("Expected \"foo bar test\"\n");
        printf("Received \"%s\"\n", string->array);
        return FALSE;
    }

    return TRUE;
}

int main() {
    printf("RUNNING Strings Tests ======================================\n");
    runTest(*cstring_to_string, 1, "CString to String");
    runTest(*StringCMP, 2, "Compare Strings");
    runTest(*slice, 3, "Slice");

    printf("\n");
    printf("RUNNING Array Strings Tests ================================\n");
    runTest(*create_array_string, 1, "Create Array String");
    runTest(*push, 2, "Push to Array String");
    runTest(array_to_string, 3, "Array String to String");
}