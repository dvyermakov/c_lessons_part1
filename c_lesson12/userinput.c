#include "userinput.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "date.h"
#include "errors.h"
#include "structs.h"

bool userInput(date_t *bDate, int *daysCount, int *measureCount){
    char tmp_str[50];
    if (bDate->Day == 0){
        printf("Введите дату начала измерений (ДД.ММ.ГГГГ): ");
        scanf("%s", tmp_str);
        if (!inputDate(tmp_str, bDate))
            return false;
    }
    if (*daysCount == 0){
        printf("Введите количество дней измерений: ");
        scanf("%s", tmp_str);
        if (!inputDaysCount(tmp_str, daysCount))
            return false;
    }
    if (*measureCount == 0){
        printf("Введите количество измерений за день: ");
        scanf("%s", tmp_str);
        if (!inputMeasureCount(tmp_str, measureCount))
            return false;
        
    }
    return true;
}

bool inputDate(char *str, date_t *bDate){  
    if ((sscanf(str, "%d.%d.%d", &bDate->Day, &bDate->Month, &bDate->Year)) != 3){
        printError(E_WRONG_DATE);
        return false;
    }  
    else{
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
    }
    return true;
}

bool inputDaysCount(char *str, int *daysCount){
    if ((sscanf(str, "%d", daysCount)) != 1){
        printError(E_WRONG_DAYS_COUNT);
        return false;
    }   
    else{
        if ((*daysCount < 1)){
            printError(E_INVALID_DAYS_COUNT);
            return false;
        }  
    }
    return true;
}

bool inputMeasureCount(char *str, int *measureCount){
    if ((sscanf(str, "%d", measureCount)) != 1){
        printError(E_WRONG_MEASURE_COUNT);
        return false;
    }
    else{
        if ((*measureCount < 1)){
            printError(E_INVALID_MEASURE_COUNT);
            return false;
        }
    }
    return true; 
}
