#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Date{
    int Day;
    int Month;
    int Year;
} date_t; 

struct LogRecord{
    date_t Date;
    int Temp;
};

#endif
