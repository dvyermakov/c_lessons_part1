#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include "date.h"
#include "errors.h"
#include "structs.h"
#include "dbg.h"

extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;

void calcAvYear(const struct Stat *statistics, float *avTemp, float *minTemp, float *maxTemp);              // вычисление среднегодовых значений
void checkMinMax(const int *temp, int *minTemp, int *maxTemp);                                              // проверка макс / мин температуры
bool procArgs(int argc, char **argv, int *month, char **fileName);                                          // обработка аргументов командной строки
void printResult(const int *month, struct Stat *statistics, const int *recCount, const int *recInvCount);   // вывод результатов вычислений
void printHelp();                                                                                           // вывод справки

int main(int argc, char **argv){
    int showMonth = 0;                      // месяц для вывода информации
    char *fileName;                         // файл с логом
    struct LogRecord rec;                   // запись лога
    int fRecNum = 0;                        // номер строки в файле
    int fRecCount = 0;                      // кол-во нормальных записей в файле
    int fRecInvCount = 0;                   // кол-во битых записей в файле
    struct Stat statistics[12];
    for (int i = 0; i < 12; ++i){           
        statistics[i].AvTemp = 0;
        statistics[i].MeasureCount = 0;
        statistics[i].MinTemp = 1000;
        statistics[i].MaxTemp = -1000;
    }
    if (! procArgs(argc, argv, &showMonth, &fileName)){
        return 0;
    }
    FILE *logFile;
    logFile = fopen(fileName, "r");
    if (logFile == NULL){
        printError(E_WRONG_FILENAME);
        return 0;
    }
    while (! feof(logFile)){
        fRecNum++;
        char str[50];
        fscanf(logFile, "%s\n", str);
        if (sscanf(str, "%d;%d;%d;%d;%d;%d", 
                        &rec.Date.Year,
                        &rec.Date.Month,
                        &rec.Date.Day,
                        &rec.Time.Hour,
                        &rec.Time.Minute,
                        &rec.Temp) != 6)
        {
            printf("Строка %d лога - неверный формат!\n", fRecNum);
            fRecInvCount++;
            continue;
        }
        else{
            fRecCount++;
            statistics[rec.Date.Month - 1].Month = rec.Date.Month;
            statistics[rec.Date.Month - 1].MeasureCount++;
            statistics[rec.Date.Month - 1].AvTemp += rec.Temp;
            checkMinMax(&rec.Temp, &statistics[rec.Date.Month - 1].MinTemp, &statistics[rec.Date.Month - 1].MaxTemp);
        }
    }
    printResult(&showMonth, statistics, &fRecCount, &fRecInvCount);
    fclose(logFile);
    return 0;
}

void calcAvYear(const struct Stat *statistics, float *avTemp, float *minTemp, float *maxTemp){
    *avTemp = statistics[0].AvTemp / statistics[0].MeasureCount;
    *minTemp = statistics[0].MinTemp;
    *maxTemp = statistics[0].MaxTemp;
    for (int i = 1; i < 12; ++i){
        *avTemp += statistics[i].AvTemp / statistics[i].MeasureCount;
        if (statistics[i].MinTemp < *minTemp){
            *minTemp = statistics[i].MinTemp;
        }
        if (statistics[i].MaxTemp > *maxTemp){
            *maxTemp = statistics[i].MaxTemp;
        }
    }
    *avTemp /= 12;
}

void checkMinMax(const int *temp, int *minTemp, int *maxTemp){
    if (*temp < *minTemp){
        *minTemp = *temp;
    }
    if (*temp > *maxTemp){
        *maxTemp = *temp;
    }
}

bool procArgs(int argc, char **argv, int *month, char **fileName){
    int opt;
    if (argc == 1){
        printHelp();
        return false;
    }
    while ((opt = getopt(argc, argv, "hfm")) != -1){
        switch (opt){
            case 'h':{
                printHelp();
                return false;
            }
            case 'f':{
                *fileName = argv[optind];
                break;
            }
             case 'm':{
                 int m = 0;
                 sscanf(argv[optind], "%d", &m);
                if ((m > 0) && (m < 12)){
                    *month = m;
                }
                else{
                    printError(E_INVALID_MONTH);
                    return false;
                }
                break;
            }
        }
    }
    return true;
}

void printResult(const int *month, struct Stat *statistics, const int *recCount, const int *recInvCount){
    if (*month == 0){
        for (int i = 0; i < 12; ++i){
            char *str;
            monthConvertToStr(statistics[i].Month, &str);
            printf("Mесяц %s:\n",  str);
            printf("\t-средняя температура: %.1f\n", statistics[i].AvTemp / statistics[i].MeasureCount);
            printf("\t-минимальная температура: %d\n", statistics[i].MinTemp);
            printf("\t-максимальная температура: %d\n", statistics[i].MaxTemp);
        }
    }
    else{
        char *str;
            monthConvertToStr(*month, &str);
            printf("Mесяц %s:\n",  str);
            printf("\t-средняя температура: %.1f\n", statistics[*month].AvTemp / statistics[*month].MeasureCount);
            printf("\t-минимальная температура: %d\n", statistics[*month].MinTemp);
            printf("\t-максимальная температура: %d\n", statistics[*month].MaxTemp);
    }
    float avTemp = 0;
    float minTemp = 0;
    float maxTemp = 0;
    calcAvYear(statistics, &avTemp, &minTemp, &maxTemp);
    printf("Среднегодовые значения:\n");
    printf("\t-температура: %.1f\n", avTemp);
    printf("\t-минимальная температура: %.1f\n", minTemp);
    printf("\t-максимальная температура: %.1f\n", maxTemp);
    printf("Количество обработанных записей лога - %d\n", *recCount);
    printf("Количество поврежденных записей лога - %d\n", *recInvCount);
}

void printHelp(){
    printf("Программа выводит статистику температурного датчика.\n");
    printf("Опции:\n");
    printf("\t-h\tвывод справки;\n");
    printf("\t-f\tимя файла лога температурного датчика (-f \"имя файла\");\n");
    printf("\t-m\tвывод статистики за определнный месяц (-m номер месяца 1-12).\n");

}