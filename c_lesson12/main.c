#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "date.h"
#include "errors.h"
#include "log.h"
#include "structs.h"
#include "userinput.h"
#include "dbg.h"

#define LOG_FILENAME    "log.txt"

extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;

bool procArgs(int argc, char **argv, date_t *bDate, int *daysCount, int *measureCount, bool *detailPrint);      // обработка аргументов командной строки
void createLog(struct LogRecord *rec, int *daysCount, int *measureCount, bool *detailPrint);                    // создание и запись лога в файл
void printHelp();                                                                                               // вывод справки

int main(int argc, char **argv){
    date_t bDate;                       // дата первого измерения
    int daysCount = 0;                  // количество дней измерений
    int measureCount = 0;               // количество измерений за день
    struct LogRecord rec;               // запись лога
    bool detailPrint = false;           // включение подробного вывода        
    
    bDate.Day = 0;
    if (! procArgs(argc, argv, &bDate, &daysCount, &measureCount, &detailPrint)){
        return 0;
    }
    if (! userInput(&bDate, &daysCount, &measureCount)){
        return 0;
    }    
    rec.Date = bDate;
    createLog(&rec, &daysCount, &measureCount, &detailPrint);
    return 0;
}

bool procArgs(int argc, char **argv, date_t *bDate, int *daysCount, int *measureCount, bool *detailPrint){
    int opt;
    while ((opt = getopt(argc, argv, "cDdhfv")) != -1){
        switch (opt){
            case 'h':{
                printHelp();
                return false;
            }
            case 'D':{
                if (!inputDate(argv[optind], bDate)){
                    return false;
                }
                break;
            }
            case 'd':{
                if (!inputDaysCount(argv[optind], daysCount)){
                    return false;
                }
                break;
            }
            case 'c':{
                if (!inputMeasureCount(argv[optind], measureCount)){
                    return false;
                }
                break;
            }
            case 'v':{
                if (((strcmp(argv[optind], "y")) == 0) ||
                    ((strcmp(argv[optind], "Y")) == 0) ||
                    ((strcmp(argv[optind], "yes")) == 0) ||
                    ((strcmp(argv[optind], "Yes")) == 0) ||
                    ((strcmp(argv[optind], "YES")) == 0)){
                    *detailPrint = true;
                }
                break;
            }
        }
    }
    return true;
}

void createLog(struct LogRecord *rec, int *daysCount, int *measureCount, bool *detailPrint){
    logCreate(LOG_FILENAME);
    while (*daysCount > 0){
        for (int i = 0; i < *measureCount; ++i){
            rec->Temp = rand() % 100 - 50;
            //printf("%d;%d;%d;%d\n", rec->Date.Day, rec->Date.Month, rec->Date.Year, rec->Temp);
            if (*detailPrint == true){
                char str[100];
                sprintf(str, "Новое измерение - %d;%d;%d;%d\n", rec->Date.Day, rec->Date.Month, rec->Date.Year, rec->Temp);
                DBG(str);
            }            
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

void printHelp(){
    printf("Программа генерирует файл с измерениями температурного датчика.\n");
    printf("Опции:\n");
    printf("\t-h\tвывод справки;\n");
    printf("\t-D\tдата начала измерений в формате ДД.ММ.ГГГГ;\n");
    printf("\t-d\tколичество дней измерений;\n");
    printf("\t-с\tколичество измерений за день;\n");
    printf("\t-v\tвывод на консоль сгенерированных значений (для включения y, Y, yes, YES, Yes).\n");
}