#include <stdio.h>

// Ввод: 2 целых числа(scanf)
// 1 - беззнаковое. Исходное число введенное пользователем для операций над ним
// 2 - знаковое. Величина сдвига.
// Если второе число больше нуля, то выполнить сдвиг ВПРАВО первого числа на количество разрядов указанных во втором числе.
// Если второе число меньше нуля, то выполнить сдвиг ВЛЕВО первого числа на количество разрядов указанных во втором числе. .
// Если второе число равно нулю, выдать сообщение об этом.
// После получения значений переменных, программа должна вывести в шестнадцатеричном представлении значение переменной 1 и результата
// Пример:
// ./main
// Enter number and shift value:
// 55 -5
// Input: 0x37 shift left 5
// Result: 0x6E0
// ./main
// Enter number and shift value:
// 55 3
// Input: 0x37 shift right 3
// Result: 0x6
// ./main
// Enter number and shift value:
// 55 0
// Zero shift is not defined

int main(void){
    unsigned int number; 
    int shift;
    printf("Enter number and shift value: \n");
    scanf("%u %d", &number, &shift);
    
    if (shift > 0){
        printf("input: 0x%x shift right %d\n", number, shift);
        number >>= shift;
        printf("Result: 0x%x\n", number);
    }
    else{
        if  (shift < 0){
            printf("input: 0x%x shift left %d\n", number, -shift);
            number <<= -shift;
            printf("Result: 0x%x\n", number);
        }
        else{
            printf("Zero shift is not defined.\n");
        }
    }
    return 0;
}