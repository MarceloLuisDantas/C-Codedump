#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file.h"

/* TODO -
 * Check all the args
 */

int main(int argc, char *argv[]) {
    if (argc != 2)
        exit(0);
    
    FileLines *lines = getLines(argv[1]);
    
    for (int i = 0; i < lines->len; i++) 
        printf("%s", lines->lines[i]);
}