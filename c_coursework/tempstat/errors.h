#ifndef ERRORS_H
#define ERRORS_H

#define E_INVALID_DAYS_COUNT        1
#define E_INVALID_MEASURE_INTERVAL  2
#define E_WRONG_DAYS_COUNT          3
#define E_WRONG_MEASURE_INTERVAL    4
#define E_WRONG_DATE                5
#define E_INVALID_YEAR              6
#define E_INVALID_MONTH             7
#define E_INVALID_DAY               8
#define E_WRONG_FILENAME            9

void printError(int errorCode);

#endif
