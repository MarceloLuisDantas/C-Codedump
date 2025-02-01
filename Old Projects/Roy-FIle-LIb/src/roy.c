#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "linked_list.h"
#include "string.h"

void removeSpace(Node *n) {
    int total_chars = 0;
    for (int i = 0; i < strlen(n->value); i++)
        if (n->value[i] != ' ')
            total_chars += 1;

    char *newValue = (char *)malloc(sizeof(char *) * total_chars + 1);
    int count = 0;
    for (int i = 0; i < strlen(n->value); i++) {
        if (n->value[i] != ' ') {
            newValue[count] = n->value[i];
            count += 1;
        }
    }
    newValue[count] = '\0';

    free(n->value);
    n->value = newValue;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("not enough args");
        exit(1);
    }

    const char *path = argv[1];

    File *f = loadFile(path);
    
    appliedToLines(f, &removeSpace);

    saveFile(f);
    
    return 0;
}
