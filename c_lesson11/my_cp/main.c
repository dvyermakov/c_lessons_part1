#include <stdio.h>
#include <stdbool.h>
#include "errors.h"
#include "my_filesys.h"

void printHelp();

int main(int argc, char** argv){
    if ((argc == 2) && (argv[1][0] == '-')){
        if (argv[1][1] == 'h'){
            printHelp();
            return 0;
        }
        else{
            printError(E_CALL_ERROR, "");
            return 0;
        }
    }
    if (argc == 3){
        cp(argv[1], argv[2]);
    }
    else{
        printError(E_CALL_ERROR, "");
    }
    return 0;
}

void printHelp(){
    printf("Программа для копирования файла.\n");
    printf("\tmy_cp \"откуда\" \"куда\"\t- копирование файла \"откуда\" в файл \"куда\"\n");
    printf("\tmy_cp -h\t\t- вызов справки\n");
}

