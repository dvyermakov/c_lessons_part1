#include <stdio.h>

// Пользователь вводит строку, состоящую из десятичных цифр, английских букв, символов пробела и так далее.
// Вычислить абсолютное и процентное соотношение символов:
// 1) цифр
// 2) английских букв верхнего регистра
// 3) английских букв нижнего регистра
// 4) пробелов
// Пример:
// Вводим "123 456 abc DEF ++"
// общая длина строки - 18 символов
// из них цифр 6, то есть примерно 33% ((float)6 / (float)18) * 100
// пробелов 4
// и так далее.

float getPercent(float numerator, float denominator); // вычисление процентов (numerator / denominator * 100)

int main(void){
    char c;
    unsigned int digitCount = 0;            // количество цифр
    unsigned int letterUpCount = 0;         // количество букв в верхнем регистре
    unsigned int letterLowCount = 0;        // количество букв в нижнем регистре
    unsigned int spaceCount = 0;            // количество пробелов
    unsigned int unknownCount = 0;          // количество остальных символов
    unsigned int lenght = 0;                // длина строки
    printf("Введите строку...\n");

    while ((c = getchar()) != '\n'){
        ++lenght;
        if (c == ' '){
            ++spaceCount;
        }
        else{
            if ((c >= '0') && (c <= '9')){
                ++digitCount;
            }
            else{
                if ((c >= 'A') && (c <= 'Z')){
                    ++letterUpCount;
                }
                else{
                    if ((c >= 'a') && (c <= 'z')){
                        ++letterLowCount;
                    }
                    else{
                        ++unknownCount;
                    }
                }
            }
        } 
    }

    printf("Всего введено символов - %u.\n", lenght);
    printf("Из них:\n");
    printf("    Количество пробелов             -   %u (%.1f %%) \n", spaceCount, getPercent(spaceCount, lenght));
    printf("    Количество цифр                 -   %u (%.1f %%) \n", digitCount, getPercent(digitCount, lenght));
    printf("    Количество букв всего           -   %u (%.1f %%) \n", letterUpCount + letterLowCount, getPercent((letterUpCount + letterLowCount), lenght));
    printf("        в верхнем регистре          -   %u (%.1f %%) \n", letterUpCount, getPercent(letterUpCount, lenght));
    printf("        в нижнем регистре           -   %u (%.1f %%) \n", letterLowCount, getPercent(letterLowCount, lenght));
    printf("    Количество неизвестных символов -   %u (%.1f %%) \n", unknownCount, getPercent(unknownCount, lenght));

    return 1;
}

float getPercent(float numerator, float denominator){
    return numerator / denominator * 100;
}