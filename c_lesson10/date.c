#include <stdio.h>
#include "date.h"

int getMonthDaysCount(int* month){
    int days = 0;
    int dayCount[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    days = dayCount[*month - 1];
    return days;
}
