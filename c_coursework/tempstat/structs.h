#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Date{
    int Day;
    int Month;
    int Year;
} date_t; 

typedef struct Time{
    int Hour;
    int Minute;
} _time_t;

struct LogRecord{
    date_t Date;
    _time_t Time;
    int Temp;
};

struct Stat{
    int Month;
    int MeasureCount;
    float AvTemp;
    int MinTemp;
    int MaxTemp;
};

#endif
