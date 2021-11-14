#include <stdio.h>
#include <stdbool.h>

// Распечатать первые n простых чисел (простое число X - это такое число X >= 2 и делится только на 1 и на себя).
// Пример:
// Пользователь вводит 5 - значит надо вывести первые 5 простых чисел
// 2 3 5 7 11

unsigned int getUserInput(void);                // функция чтения ввода пользователя
bool isPrimeNumber(unsigned int number);        // функция для определения простых чисел


int main(void){
    int numberCount = 0;                        // хранение ввода пользователя - количество простых чисел
    while (numberCount <= 0){                    // запрос от пользователя до получения корректного значения (целое число больше нуля)
        numberCount = getUserInput();
    }
    int i = 0;                                  // счетчик найденных простых чисел
    unsigned int number = 2;                    // число "кандидат" в простые
    while (i < numberCount){
        if (isPrimeNumber(number)){             // если число - простое
            printf("%u ", number);              // выводим его на экран
            ++i;                                // изменяем счетчик найденных чисел
        }
        ++number;                               // проверка следующего "кандидата"
    }
    printf("\n");
    return 0;
}

unsigned int getUserInput(void){
    int input;
    printf("Введите количество чисел (целое больше нуля): \n");
    int count = scanf("%d", &input);
    if (count != 1){
        printf("Ошибка - введено не целое число.\n");
        scanf("%*s");
        input = 0;
    }
    else {
        if (input <= 0){
            printf("Ошибка - введено число меньше нуля.\n");
            input = 0;
        }
    }
    return input;
}

bool isPrimeNumber(unsigned int number){ 
    bool isPrime = true;
    for (int i = 2; i < number; ++i){
        if ((number % i) == 0){
            isPrime = false;
            break;
        }
    }
    return isPrime;
}