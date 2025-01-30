from os import system
from sys import argv

def newFolder(folderName: str) :
    result: int = system("mkdir " + folderName + " 2> /dev/null")
    if (result != 0) :
        print("pasta " + folderName + " já existe")

def newFile(folderName: str) :
    result: int = system("touch " + folderName + "/main.c 2> /dev/null")
    if (result != 0) :
        print("Arquivo " + folderName + "/main.c já existe")

def writeToFile(folderName: str) :
    code: str = """#include <stdio.h>

int main() {
    printf("Hello World\\n");
    return 0;
}
"""
    result: int = system("echo \"{:s}\" > ./{:s}/main.c 2> /dev/null".format(code, folderName))
    if (result != 0) :
        print("Não foi possivel escrever no arquivo")

def main() :
    if (len(argv) != 3) :
        print("Quantidade errada de arqumentos")
    else :
        folderName: str = argv[1] + "\ " + argv[2]
        newFolder(folderName) 
        newFile(folderName)
        writeToFile(folderName)
    
main()