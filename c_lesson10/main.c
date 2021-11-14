#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "date.h"
#include "errors.h"
#include "log.h"
#include "structs.h"

#define LOG_FILENAME    "log.txt"

bool userInput(date_t* bDate, int* daysCount, int* measureCount);           // получение информации от пользователя
void createLog(struct LogRecord* rec, int* daysCount, int* measureCount);   // создание и запись лога в файл

int main(void){
    date_t bDate;               // дата первого измерения
    int daysCount;              // количество дней измерений
    int measureCount;           // количество измерений за день
    struct LogRecord rec;       // запись лога
    if (!(userInput(&bDate, &daysCount, &measureCount)))
        return 0;    
    rec.Date = bDate;
    createLog(&rec, &daysCount, &measureCount);
    return 0;
}

bool userInput(date_t* bDate, int* daysCount, int* measureCount){
    printf("Введите дату начала измерений (ДД.ММ.ГГГГ): ");
    if ((scanf("%d.%d.%d", &bDate->Day, &bDate->Month, &bDate->Year)) != 3){
        printError(E_WRONG_DATE);
        return false;
    }
    if (bDate->Year < 0){
        printError(E_INVALID_YEAR);
        return false;
    }
    if ((bDate->Month < 1) || (bDate->Month > 12)){
        printError(E_INVALID_MONTH);
        return false;
    }
    if ((bDate->Day < 1) || (bDate->Day > (getMonthDaysCount(&bDate->Month)))){
        printError(E_INVALID_DAY);
        return false;
    }
    printf("Введите количество дней измерений: ");
    if ((scanf("%d", daysCount)) != 1){
        printError(E_WRONG_DAYS_COUNT);
        return false;
    }    
    if ((*daysCount < 1)){
        printError(E_INVALID_DAYS_COUNT);
        return false;
    }    
    printf("Введите количество измерений за день: ");
    if ((scanf("%d", measureCount)) != 1){
        printError(E_WRONG_MEASURE_COUNT);
        return false;
    }
    if ((*measureCount < 1)){
        printError(E_INVALID_MEASURE_COUNT);
        return false;
    }
    return true;
}

void createLog(struct LogRecord* rec, int* daysCount, int* measureCount){
    logCreate(LOG_FILENAME);
    while (*daysCount > 0){
        for (int i = 0; i < *measureCount; ++i){
            rec->Temp = rand() % 100 - 50;
            //printf("%d;%d;%d;%d\n", rec->Date.Day, rec->Date.Month, rec->Date.Year, rec->Temp);
            logAppend(LOG_FILENAME, rec);
        }     
        rec->Date.Day++;           
        if ((rec->Date.Day > 31) && (rec->Date.Month == 12)){       // смена года
            rec->Date.Year++;
            rec->Date.Day = 1;
            rec->Date.Month = 1;
        }   
        if (rec->Date.Day > getMonthDaysCount(&rec->Date.Month)){   // смена месяца
            rec->Date.Day = 1;
            rec->Date.Month++;
        }
        (*daysCount)--;
    }
}
