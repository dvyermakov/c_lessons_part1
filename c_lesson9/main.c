#include <stdio.h>

// Домашнее задание : текстовый калькулятор.
// Пользователь вводит строку вида 12345+5678-1235/2567*12356
// Программа должна выполнить все операции по порядку. То есть сначала 12345+5678
// Потом -1235
// потом /2567
// и так далее.

void calculate(int* p_result, int* p_operand, char* p_operation, char* error); 
void printErrorMessage(char* error);

int main(void){
    char errCode = 0;                                                       // хранение кода ошибки
    int result = 0;
    int operand = 0;
    char operation = '+';                                                   // '+' - для записи самого первого операнда в result (result = 0 + operand)
    char ch;
    printf("Введите строку для вычисления.\n");
    printf("Поддерживаются беззнаковые целые числа и следующие операции +, -, *, /, %%.\n");
    while ((ch = getchar()) != '\n') {
        if ((ch >= '0') && (ch <= '9')){                                    // получение операнда
            operand *= 10;
            operand += ch - '0';
            continue;
        } 
        else{            
            if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%')){
                if (operand != 0){
                    calculate(&result, &operand, &operation, &errCode);     // вычисление старой операции
                    operation = ch;                                         // запоминание новой операции
                    operand = 0;                                            // обнуление операнда перед получением нового
                }
                else{                                                       // Ошибка вида "12+-10", "-6*2"
                    errCode = 3;
                    break;
                }                    
            } 
            else{                                                           // Ошибка - неподдерживаемые символы
                errCode = 2;
                break;
            }           
        }        
    }
    calculate(&result, &operand, &operation, &errCode);                     // выполнение последней запомненной операции
    if (errCode == 0){        
        printf("Результат вычисления: %d\n", result);
    }
    else{
        printErrorMessage(&errCode);
    }
    return 0;
}

void calculate(int* p_result, int* p_operand, char* p_operation, char* error){
    switch (*p_operation){
        case '+':{
            *p_result += *p_operand;
            break;
        }
        case '-':{
            *p_result -= *p_operand;
            break;
        }
        case '*':{
            *p_result *= *p_operand;
            break;
        }
        case '/':{
            if (*p_operand != 0)
                *p_result /= *p_operand;
            else
                *error = 1;
            break;
        }
        case '%':{
            if (*p_operand != 0)
                *p_result %= *p_operand;
            else
                *error = 1;
            break;
        }
    }
}

void printErrorMessage(char* error){
    printf("Ошибка! ");
    switch (*error){
        case 1:{
            printf("Делить на 0 НЕЛЬЗЯ!\n");
            break;
        }
        case 2:{
            printf("Введены неподдерживаемые символы.\n");
            break;
        }
        case 3:{
            printf("Неправильная расстановка знаков операций.\n");
            break;
        }
    }
}
