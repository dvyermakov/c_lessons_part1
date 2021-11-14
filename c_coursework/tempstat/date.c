#include <stdio.h>
#include "date.h"

int getMonthDaysCount(int *month){
    int days = 0;
    int dayCount[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    days = dayCount[*month - 1];
    return days;
}

void monthConvertToStr(int month, char **str){
    switch (month){
        case 1:{
            *str = "Январь";
            break;
        }
        case 2:{
            *str = "Февраль";
            break;
        }
        case 3:{
            *str = "Март";
            break;
        }
        case 4:{
            *str = "Апрель";
            break;
        }
        case 5:{
            *str = "Май";
            break;
        }
        case 6:{
            *str = "Июнь";
            break;
        }
        case 7:{
            *str = "Июль";
            break;
        }
        case 8:{
            *str = "Август";
            break;
        }
        case 9:{
            *str = "Сентябрь";
            break;
        }
        case 10:{
            *str = "Октябрь";
            break;
        }
        case 11:{
            *str = "Ноябрь";
            break;
        }
        case 12:{
            *str = "Декабрь";
            break;
        }
    }
}
