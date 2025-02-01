#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Files/Files.h"
#include "Strings/Strings.h"
#include "Sintaxes/sintaxes.h"
#include "Linked List/labels_list.h"
#include "Linked List/linked_list.h"

void remove_comments(File *file) {
    Node *sup = file->lines->start;
    for (int i = 0; i < file->len; i++) {
        char **splits = split(sup->value, ';');
        reallocAndCopy(&(sup->value), splits[0]);
        free(splits);
        sup = sup->next;
    }
}

void remove_white_spaces(File *file) {
    Node *sup = file->lines->start;
    for (int i = 0; i < file->len; i++) {
        removeExtraSpaces(&(sup->value));
        sup = sup->next;
    }
}

int check_sintaxes(File *file) {
    char **lines = toArray(file->lines);
    int errors = 0;
    for (int i = 0; i < file->len; i++) {
        char **splits = split(lines[i], ' ');
        if (strcmp(splits[0], "\0") != 0) {
            errors += check_sintaxe(splits, i);
        }
        free(splits);
    }
    free(lines);
    return errors;
}

// Função delete esta bugada arrumar depois
void remove_empty_lines(File *file) {
    char **lines = toArray(file->lines);
    for (int i = file->len - 1; i >= 0; i--)
        if (isEmptyStr(lines[i]) == 1)
            delete(file->lines, i);
}

int labels_to_line(File *File) {
    LabelList *list = newLabelList();
    char **lines = toArray(File->lines);
    for (int i = 0; i < File->len; i++) {
        char **args = split(lines[i], ' ');
        if (label_sintaxe_s(args) == 0) {
            char *label = getSlice(args[0], 0, strlen(args[0]) - 1);
            addLabel(list, label, i + 1);
        }
        free(args);
    }
    free(lines);
    
    Node *sup = File->lines->start;
    int errs = 0;
    int line = 1;
    while (sup != NULL) {
        char **args = split(sup->value, ' ');
        if (strcmp(args[0], "jump") == 0 || strcmp(args[0], "jal") == 0) {
            char **newL = (char **)malloc(sizeof(char *) * 3);
            reallocAndCopy(&(newL[0]), args[0]);
            int l_line = getLine(list, args[1]);
            if (l_line == -1) {
                printf("Line %d - \"%s\"\n", line, sup->value);
                printf(" - Label not found = %s\n", args[3]);
                errs += 1;
            } else {
                intToStr(&(newL[1]),  l_line);
                reallocAndCopy(&(newL[2]), "\0");
            }
            // char *full = arrayToString(newL);
            // printf("%s\n", full);
        } else if (strcmp(args[0], "beq") == 0 || strcmp(args[0], "bne") == 0)  {
            char **newL = (char **)malloc(sizeof(char *) * 5);
            reallocAndCopy(&(newL[0]), args[0]);
            reallocAndCopy(&(newL[1]), args[1]);
            reallocAndCopy(&(newL[2]), args[2]);
            int l_line = getLine(list, args[3]);
            if (l_line == -1) {
                printf("Line %d - \"%s\"\n", line, sup->value);
                printf(" - Label not found = %s\n", args[3]);
                errs += 1;
            } else {
                intToStr(&(newL[3]), l_line);
                reallocAndCopy(&(newL[4]), "\0");
            }
            // char *full = arrayToString(newL);
            // printf("%s\n", full);
        }
        free(args);
        line += 1;
        sup = sup->next;
    }
    return errs;
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("incorrect arguments\n");
        return 0;
    }

    const char *path = argv[1];
    File *file = loadFile(path);

    remove_comments(file);
    remove_white_spaces(file);
    // remove_empty_lines(file);
    int errors = check_sintaxes(file);
    if (errors > 0) {
        freeFile(file);
        exit(1);
    }

    int label_err = labels_to_line(file);
    if (label_err != 0) {
        freeFile(file);
        exit(1);
    }

    saveFile(file, "out.asm");
    freeFile(file);


    return 0;
}
