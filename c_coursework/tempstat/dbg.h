#ifndef DBG_H
#define DBG_H

#include <stdio.h>

// Для вывода отладочных сообщений

#ifdef DEBUG
    #define DBG(s)              printf("File: %s line: %d function: %s - %s\n", __FILE__, __LINE__, __func__, s);
    #define DBGINT(s, i)        printf("Int %s = %d\n", s, i);
    #define DBGSTR(sName, s)    printf("%s = %s\n", sName, s);
    #define DBGSTRUCT(struct)   printf("%d.%d.%d temp %d\n", struct.Date.Year, struct.Date.Month, struct.Date.Day, struct.Temp);
#else
    #define DBG(s)
    #define DBGINT(s, i)
    #define DBGSTR(sName, s)
    #define DBGSTRUCT(struct)
#endif

#endif
