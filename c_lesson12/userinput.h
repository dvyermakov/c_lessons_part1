#ifndef USERINPUT_H
#define USERINPUT_H

#include <stdio.h>
#include <stdbool.h>
#include "structs.h"
#include "errors.h"

bool userInput(date_t *bDate, int *daysCount, int *measureCount);
bool inputDate(char *str, date_t *bDate);                                          // ввод и проверка даты начала измерений
bool inputDaysCount(char *str, int *daysCount);                                    // ввод и проверка количества дней измерений
bool inputMeasureCount(char *str, int *measureCount);                              // ввод и проверка количества измерений за день

#endif
