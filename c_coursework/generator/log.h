#ifndef LOG_H
#define LOG_H
#include "structs.h"

void logCreate(char* filename);                             // создание файла или стирание старого содержимого
void logAppend(char* filename, struct LogRecord* rec);      // добавление записи в конец файла

#endif
