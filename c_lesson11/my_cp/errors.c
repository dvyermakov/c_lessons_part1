#include <stdio.h>
#include "errors.h"

void printError(int errorCode, char* comment){
    printf("Ошибка! ");
    switch (errorCode){
        case E_CALL_ERROR:{
            printf("Неправильный вызов команды\n");
            printf("Для получения справки введите my_cp -h.\n");
            break;
        } 
        case E_FILE_OPEN:{
            printf("Файл %s не существует.\n", comment);
            break;
        } 
        case E_NOT_FILE:{
            printf("%s не является файлом.\n", comment);
            break;
        }        
    }
}
