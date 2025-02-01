#ifndef LABEL_LIST_H
#define LABEL_LIST_H

typedef struct LabelNode {
    struct LabelNode *next;
    char *label;
    int line;
} LabelNode;

typedef struct LabelList {
    LabelNode *start;
} LabelList;

LabelNode *newLabelNode(char *label, int line);
LabelList *newLabelList();
void addLabel(LabelList *list, char *label, int line);
int getLine(LabelList *list, char *label);

#endif