#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct LabelNode {
    struct LabelNode *next;
    char *label;
    int line;
} LabelNode;

LabelNode *newLabelNode(char *label, int line) {
    LabelNode *node = (LabelNode *)malloc(sizeof(LabelNode));
    node->next = NULL;
    node->label = (char *)malloc(sizeof(char) * strlen(label) + 1);
    strcpy(node->label, label);
    node->line = line;
    return node;
}

typedef struct LabelList {
    LabelNode *start;
} LabelList;

LabelList *newLabelList() {
    LabelList *list = (LabelList *)malloc(sizeof(LabelList));
    list->start = NULL;
    return list;
}

void addLabel(LabelList *list, char *label, int line) {
    LabelNode *node = newLabelNode(label, line);
    if (list->start == NULL) {
        list->start = node;
        return;
    }

    LabelNode *sup = list->start;
    while (sup->next != NULL)
        sup = sup->next;
    sup->next = node;
}

int getLine(LabelList *list, char *label) {
    if (list->start == NULL)
        return -1;

    LabelNode *sup = list->start;
    for (;;) {
        if (strcmp(sup->label, label) == 0)
            return sup->line;
        if (sup->next == NULL)
            return -1;
        sup = sup->next;
    }
}
