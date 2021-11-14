#include <stdio.h>
#include <stdbool.h>

unsigned int get_uint(void);
double getDouble(void); // ввод числа float

int main(void){
    printf("Введите число через .\n");
    printf("Введено число - %f \n", getDouble());
    return 1;
}

unsigned int get_uint(void){
    char c;
    unsigned int number = 0;
    while((c = getchar()) != '\n'){
        if (c >= '0' && c <= '9'){
            number *= 10;
            number += c - '0';
        }
    }
    return number;
}

double getDouble(void){
    char c;
    bool takeMinus = false;                 // получен ли '-'
    bool posMinus = true;                   // '-' может быть только перед числом
    bool takeDot = false;                   // получен ли разделитель '.'
    int whPart = 0;                         // целая часть числа
    unsigned int frPart = 0;                // дробная часть числа
    unsigned int frPartDigitCount = 0;      // количество знаков дробной части
    double result = 0;                      // результат
    while ((c = getchar()) != '\n'){        
        if ((c >= '0') && (c <= '9')){
            posMinus = false;
            if (! takeDot){
                // целая часть
                whPart *= 10;
                whPart += c - '0';
            }
            else{
                // дробная часть
                frPart *= 10;
                frPart += c - '0';
                ++frPartDigitCount;
            }
        }
        else{
            if ((c == '.') && (! takeDot)){ // введена точка, причем только одна
                takeDot = true;
            }
            else{
                if ((c == '-') && (! takeMinus) && posMinus){ // введен '-' на первом месте и один
                    takeMinus = true;
                }
                else{
                    // Ошибка ввода
                    printf("Ошибка ввода!\n");
                    return 0;
                }
            }
        }
    }
    result = frPart;
    for (int i = frPartDigitCount; i > 0; --i){
        result /= 10;
    }
    if (takeMinus){
        return (- (result + whPart));
    }
    return result + whPart;
}
