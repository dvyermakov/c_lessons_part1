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
    fprintf(file, "%d;%d;%d;%d;%d;%d\n", rec->Date.Year, rec->Date.Month, rec->Date.Day, rec->Time.Hour, rec->Time.Minute, rec->Temp);
    fclose(file);
}
