#include <stdio.h>
#include "log.h"

void logCreate(char* filename){
    FILE *file;
    file = fopen(filename, "w");
    fclose(file);
}

void logAppend(char* filename, struct LogRecord* rec){
    FILE *file;
    file = fopen(filename, "a+");
    fprintf(file, "%d;%d;%d;%d\n", rec->Date.Day, rec->Date.Month, rec->Date.Year, rec->Temp);
    fclose(file);
}
