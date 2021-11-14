#ifndef DBG_H
#define DBG_H

#include <stdio.h>

// Для вывода отладочных сообщений

#ifdef DEBUG
    #define DBG(s)  printf("File: %s line: %d function: %s - %s", __FILE__, __LINE__, __func__, s);
    #define DBGINT(s, i)  printf("Int %s = %d", s, i);
#else
    #define DBG(s)
    #define DBGINT(s, i)
#endif

#endif
