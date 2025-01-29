#include <stdio.h>
#include "../src/Strings.h"

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

int trim_left_test() {
    String *s_ee = CStringToString("    teste     teste      teste    ");  
    trim_left(&s_ee);
    if (StringCmp(s_ee, CStringToString("teste     teste      teste    ")) != TRUE) {
        printf("Unespected String value\n");
        printf("Expected \"teste teste teste\"\n");
        printf("Received '%s'\n", s_ee->array);
        return FALSE;
    }
    
    String *emptys = CStringToString("     ");
    trim_left(&emptys);
    if (emptys->array != NULL) {
        printf("Empty String shoulda be NULL after trim\n");
        return FALSE;
    }

    String *s = CStringToString("    te   ste");
    trim_left(&s);
    if (StringCmp(s, CStringToString("te   ste")) != TRUE) {
        printf("Unespected string value\n");
        printf("Expected \"te   ste\"\n");
        printf("Received '%s'\n", s->array);
        return FALSE;
    }

    String *s2 = CStringToString("te   ste");
    trim_left(&s2);
    if (StringCmp(s2, CStringToString("te   ste")) != TRUE) {
        printf("Unespected string value\n");
        printf("Expected \"te   ste\"\n");
        printf("Received '%s'\n", s2->array);
        return FALSE;
    }

    return TRUE;
}

int trim_right_test() {
    String *s_ee = CStringToString("    teste     teste      teste    ");  
    trim_right(&s_ee);
    if (StringCmp(s_ee, CStringToString("    teste     teste      teste")) != TRUE) {
        printf("Unespected String value\n");
        printf("Expected \"teste teste teste\"\n");
        printf("Received '%s'\n", s_ee->array);
        return FALSE;
    }

    String *emptys = CStringToString("     ");
    trim_right(&emptys);
    if (emptys->array != NULL) {
        printf("Empty String shoulda be NULL after trim\n");
        return FALSE;
    }

    String *s = CStringToString("te   ste    ");
    trim_right(&s);
    if (StringCmp(s, CStringToString("te   ste")) != TRUE) {
        printf("Unespected string value\n");
        printf("Expected \"te   ste\"\n");
        printf("Received '%s'\n", s->array);
        return FALSE;
    }

    String *s2 = CStringToString("te   ste");
    trim_right(&s2);
    if (StringCmp(s2, CStringToString("te   ste")) != TRUE) {
        printf("Unespected string value\n");
        printf("Expected \"te   ste\"\n");
        printf("Received '%s'\n", s2->array);
        return FALSE;
    }

    return TRUE;
}

int trim_test() {
    String *emptys = CStringToString("     ");
    trim(&emptys);
    if (emptys->array != NULL) {
        printf("Empty String shoulda be NULL after trim\n");
        return FALSE;
    }

    String *s = CStringToString("     te   ste    ");
    trim(&s);
    if (StringCmp(s, CStringToString("te   ste")) != TRUE) {
        printf("Unespected string value\n");
        printf("Expected \"te   ste\"\n");
        printf("Received '%s'\n", s->array);
        return FALSE;
    }

    String *s2 = CStringToString("te   ste");
    trim(&s2);
    if (StringCmp(s2, CStringToString("te   ste")) != TRUE) {
        printf("Unespected string value\n");
        printf("Expected \"te   ste\"\n");
        printf("Received '%s'\n", s2->array);
        return FALSE;
    }

    return TRUE;
}

int remove_spaces_test() {
    String *nulls = CStringToString("        ");
    remove_white_space(&nulls);
    if (nulls->array != NULL) {
        printf("String should be NULL\n");
        printf("Expected NULL\n");
        printf("Received '%s'\n", nulls->array);
        return FALSE;
    }
    
    String *s = CStringToString("    teste     teste      teste    ");
    remove_white_space(&s);
    if (StringCmp(s, CStringToString("teste teste teste")) != TRUE) {
        printf("Unespected String value\n");
        printf("Expected \"teste teste teste\"\n");
        printf("Received '%s'\n", s->array);
        return FALSE;
    }

    String *s2 = CStringToString("    teste     teste      teste");
    remove_white_space(&s2);
    if (StringCmp(s2, CStringToString("teste teste teste")) != TRUE) {
        printf("Unespected String value\n");
        printf("Expected \"teste teste teste\"\n");
        printf("Received '%s'\n", s2->array);
        return FALSE;
    }

    String *s3 = CStringToString("teste     teste      teste");
    remove_white_space(&s3);
    if (StringCmp(s3, CStringToString("teste teste teste")) != TRUE) {
        printf("Unespected String value\n");
        printf("Expected \"teste teste teste\"\n");
        printf("Received '%s'\n", s3->array);
        return FALSE;
    }

    String *s4 = CStringToString("teste teste teste");
    remove_white_space(&s4);
    if (StringCmp(s3, CStringToString("teste teste teste")) != TRUE) {
        printf("Unespected String value\n");
        printf("Expected \"teste teste teste\"\n");
        printf("Received '%s'\n", s4->array);
        return FALSE;
    }

    return TRUE;
}

int split_test() {
    String *nul = CStringToString("  ");
    ArrayString *snull = split(nul, ' ');
    if (snull != NULL) {
        printf("Array should be null");
        return FALSE;
    }

    String *s = CStringToString("   teste   teste   teste  ");
    ArrayString *as = split(s, ' ');
    if (as->len != 3) {
        printf("The Splited Array should be 3 len\n");
        String *b = arrayToString(as);
        printf("Expected: \"teste teste teste\"\n");
        printf("Received: \"%s\"\n", b->array);
        return FALSE;
    }

    String *s2 = CStringToString("   teste   teste   ");
    ArrayString *as2 = split(s2, ' ');
    if (as2->len != 2) {
        printf("The Splited Array should be 2 len\n");
        String *b = arrayToString(as2);
        printf("Expected: \"teste teste\"\n");
        printf("Received: \"%s\"\n", b->array);
        return FALSE;
    }

    String *s3 = CStringToString("teste   teste");
    ArrayString *as3 = split(s3, ' ');
    if (as3->len != 2) {
        printf("The Splited Array should be 2 len\n");
        String *b = arrayToString(as3);
        printf("Expected: \"teste teste\"\n");
        printf("Received: \"%s\"\n", b->array);
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

// ===============================================
// ============== RUNNING ALL TESTS ============== 
// ===============================================

int main() {
    printf("RUNNING Strings Tests ======================================\n");
    runTest(*cstring_to_string, 1, "CString to String");
    runTest(*StringCMP, 2, "Compare Strings");
    runTest(*slice, 3, "Slice");
    runTest(*trim_left_test, 4, "Trim Left");
    runTest(*trim_right_test, 5, "Trim Right");
    runTest(*trim_test, 6, "Trim");
    runTest(*remove_spaces_test, 7, "Remove Spaces");
    runTest(*split_test, 8, "Split");

    printf("\n");
    printf("RUNNING Array Strings Tests ================================\n");
    runTest(*create_array_string, 1, "Create Array String");
    runTest(*push, 2, "Push to Array String");
    runTest(array_to_string, 3, "Array String to String");
}