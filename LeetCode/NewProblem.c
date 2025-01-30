#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void newFolder(const char *FolderName) {
    char command[strlen(FolderName) + strlen("mkdir 2> /dev/null")];
    sprintf(&command, "mkdir %s 2> /dev/null", FolderName);
    int resultFolder = system(command);
    if (resultFolder != 0) 
        printf("Pasta \"%s\" já existe\n", FolderName);
}

void newFile(const char *FolderName) {
    char command1[strlen("touch ./") + strlen(FolderName) + strlen("/main.c 2> /dev/null")];
    sprintf(&command1, "touch ./%s/main.c 2> /dev/null", FolderName);
    int result = system(command1);
    if (result != 0)
        printf("Arquivo \"%s/main.c\" já existe\n");
}

void writeToFile(const char *FolderName) {
    char code[250] = 
        "#include<stdio.h> \n\nint main() {\n    printf(\"Hello World\\n\");\n    return 0;\n}\n";

    char echo[strlen("echo \"\" > /main.c 2> /dev/null") + strlen(FolderName) + 250];
    sprintf(&echo, "echo \"%s\" > %s/main.c 2> /dev/null", code, FolderName);
    int resultw = system(echo);
    if (resultw != 0) 
        printf("Não foi possivel escrever no arquivo, err %d\n", resultw);
}

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("Quantidade errada de argumentos\n");
        return 1;
    }
    
    char FolderName[strlen(argv[1]) + strlen(argv[2]) + 10];
    sprintf(&FolderName, "%s\\ -\\ %s", argv[1], argv[2]);
    newFolder(FolderName);
    newFile(FolderName);
    writeToFile(FolderName);
    return 0;
}
