#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void intToStr(char **s, int num) {
    *s = (char *)malloc(sizeof(char) * (int)(ceil(log10(num))) + 1);
    sprintf(*s, "%d", num);
}

int main() {
    char *teste;
    intToStr(&teste, 10);
    printf("%s\n", teste);

    return 0;
}
