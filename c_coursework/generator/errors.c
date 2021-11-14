#include <stdio.h>
#include "errors.h"

void printError(int errorCode){
    printf("Ошибка! ");
    switch (errorCode){
        case E_INVALID_DAYS_COUNT:{
            printf("Неверное количество дней измерений (должно быть > 0).\n");
            break;
        }
        case E_INVALID_MEASURE_INTERVAL:{
            printf("Неверный интервал (должно быть > 0).\n");
            break;
        }
        case E_WRONG_DAYS_COUNT:{
            printf("Количество дней измерений это число (должно быть > 0).\n");
            break;
        }
        case E_WRONG_MEASURE_INTERVAL:{
            printf("Интервал измерений это число (должно быть > 0).\n");
            break;
        }
        case E_WRONG_DATE:{
            printf("Неверно введена дата начала измерений.\n");
            break;
        }
        case E_INVALID_YEAR:{
            printf("Неверно введен год (должен быть > 0).\n");
            break;
        }
        case E_INVALID_MONTH:{
            printf("В году 12 месяцев.\n");
            break;
        }
        case E_INVALID_DAY:{
            printf("Неправильно введен день.\n");
            break;
        }
        case E_WRONG_FILENAME:{
            printf("Неправильно задан файл для записи лога.\n");
            break;
        }
    }
}
