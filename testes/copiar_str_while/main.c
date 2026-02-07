#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char temp[] = "hello world!!";
    char *str2 = malloc(sizeof(char) * (strlen(temp) + 1));
    char *str3 = malloc(sizeof(char) * (strlen(temp) + 1));
    memcpy(str2, temp, strlen(temp) + 1); 
    
    while (*str3++ = *str2++);

    printf("\"%s\"\n", str3);
}