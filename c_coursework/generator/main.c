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

bool procArgs(int argc, char **argv, date_t *bDate, int *daysCount, int *measureInterval, bool *detailPrint, char **fileName);   // обработка аргументов командной строки
void createLog(struct LogRecord *rec, int *daysCount, int *measureInterval, bool *detailPrint, char **fileName);                 // создание и запись лога в файл
void printHelp();                                                                                                               // вывод справки

int main(int argc, char **argv){
    date_t bDate;                       // дата первого измерения
    int daysCount = 0;                  // количество дней измерений
    int measureInterval = 0;            // интервал измерений в минутах
    struct LogRecord rec;               // запись лога
    bool detailPrint = false;           // включение подробного вывода       
    char *fileName = LOG_FILENAME; 
    
    bDate.Day = 0;
    if (! procArgs(argc, argv, &bDate, &daysCount, &measureInterval, &detailPrint, &fileName)){
        return 0;
    }
    if (! userInput(&bDate, &daysCount, &measureInterval)){
        return 0;
    }    
    rec.Date = bDate;
    createLog(&rec, &daysCount, &measureInterval, &detailPrint, &fileName);
    return 0;
}

bool procArgs(int argc, char **argv, date_t *bDate, int *daysCount, int *measureInterval, bool *detailPrint, char **fileName){
    int opt;
    while ((opt = getopt(argc, argv, "Ddhfiv")) != -1){
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
            case 'i':{
                if (!inputMeasureInterval(argv[optind], measureInterval)){
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
            case 'f':{
                *fileName = argv[optind];
                break;
            }
        }
    }
    return true;
}

void createLog(struct LogRecord *rec, int *daysCount, int *measureInterval, bool *detailPrint, char **fileName){
    logCreate(*fileName);
    while (*daysCount > 0){
        rec->Time.Hour = 0;
        rec->Time.Minute = 0;
        while (rec->Time.Hour < 24){
            while (rec->Time.Minute < 60){
                rec->Temp = rand() % 100 - 50;
                if (*detailPrint == true){
                    char str[100];
                    sprintf(str, "Новое измерение - %d;%d;%d;%d;%d;%d\n", rec->Date.Year, rec->Date.Month, rec->Date.Day, rec->Time.Hour, rec->Time.Minute, rec->Temp);
                }  
                logAppend(*fileName, rec);
                rec->Time.Minute += *measureInterval;                 
            }
            rec->Time.Minute = 0;
            rec->Time.Hour++;
        }
        rec->Time.Hour = 0;
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
    printf("\t-i\tинтервал измерений в минутах;\n");
    printf("\t-f\tимя файла для записи лога;");
    printf("\t-v\tвывод на консоль сгенерированных значений (для включения y, Y, yes, YES, Yes).\n");
}