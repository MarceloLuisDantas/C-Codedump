#include <stdio.h>


typedef struct Intro {
    void (*cumprimento)(void);
} Intro;


void hello() {
    printf("Hello\n");
}

void ola() {
    printf("Ola\n");
}

int main() {
    Intro intros[] = {
        { hello },
        { ola },
    };

    intros[0].cumprimento();
    intros[1].cumprimento();

    return 0;
}