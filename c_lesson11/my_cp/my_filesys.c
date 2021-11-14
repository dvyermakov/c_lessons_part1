#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "my_filesys.h"
#include "errors.h"

bool isFileExist(char* filename){
    FILE* f;
    if ((f = fopen(filename, "r")) != NULL){
        fclose(f);
        return true;
    }
    return false;
}

void cp(char* file_from, char* file_to){
    struct stat file_stat;
    if (stat(file_from, &file_stat) != -1){                 // исходный файл существует
        if ((file_stat.st_mode & S_IFMT) == S_IFREG){       // является файлом, а не директорией, ссылкой и т.д.
            FILE* from;
            from = fopen(file_from, "rb"); 
            if (isFileExist(file_to)){                      // если целевой файл существует то
                printf("Файл %s существует.\n", file_to);   // либо заменить его, либо завершение
                printf("Заменить его? (y/N): ");
                char yes_no = 'N';
                scanf("%c", &yes_no);
                if ((yes_no == 'N') || (yes_no == 'n')){
                    printf("Копирование отменено.\n");
                    return;
                }
            }
            FILE* to;        
            to = fopen(file_to, "wb");
            int buf[1024];
            int sz = 0;
            while ((sz = fread(buf, sizeof(int), 1024, from)) != 0){    // копирование
                fwrite(buf, sizeof(int), sz, to);            
            }
            fclose(from);
            fclose(to);
            printf("Копирование завершено.\n");
        }
        else{
            printError(E_NOT_FILE, file_from);
        }
    } 
    else {
        printError(E_FILE_OPEN, file_from);
    }       
}
