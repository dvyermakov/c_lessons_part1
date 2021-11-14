#ifndef ERRORS_H
#define ERRORS_H

#define E_CALL_ERROR        1   // ошибка в вызове программы
#define E_FILE_OPEN         2   // файл для копирования отсутсвует
#define E_NOT_FILE          3   // не является файлом

void printError(int errorCode, char* comment);

#endif
