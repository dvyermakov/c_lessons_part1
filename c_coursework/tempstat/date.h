#ifndef DATE_H
#define DATE_H

#include "structs.h"

int getMonthDaysCount(int *month);              // ф-ия возвращает количество дней в месяце (високосный год не учитывается)
void monthConvertToStr(int month, char **str);  // перевод номера месяца в название 

#endif
