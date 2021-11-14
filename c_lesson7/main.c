#include <stdio.h>
#include <stdbool.h>

// Программа "стрельба в мишень"
// Пользователь вводит с клавиатуры 3 числа типа float(X, Y, Radius)
// Первая функция вида
// bool get_user_input(float *X, float *Y, float *R)
// считывает с клавиатуры значения координат X,Y и радиуса, и проводит валидацию входных значений.
// (количество успешных преобразований от функции scanf, неотрицательный и ненулевой радиус и так далее)
// Если происходит ошибка - функция возвращает false. В этом случае программа с ошибкой завершается.
// Вторая функция вида
// bool is_target_hit(float X, float Y, float R)
// проверяет, попал ли пользователь в мишень. Формула X*X + Y*Y < R*R
// Результат выводится на экран(printf)

bool getUserInput(float* x, float* y, float* radius);
bool isTargetHit(float x, float y, float radius);

int main(void){
    float x = 0;
    float y = 0;
    float radius = 0;
    if (getUserInput(&x, &y, &radius)){
        if (isTargetHit(x, y, radius)){
            printf("Есть попадание в мишень!\n");
        }
        else{
            printf("Промах. Попробуйте еще.\n");
        }
    }
    return 0;
}

bool getUserInput(float* x, float* y, float* radius){
    bool result = false;
    printf("Введите координаты выстрела (X, Y) и радиус мишени (больше 0): ");
    int scanCount = scanf("%f%f%f", x, y, radius);
    if (scanCount == 3){
        if (*radius > 0){
            result = true;
        }
        else{
            printf("Введен некорректный радиус мишени!\n");
        }
    }
    else{
        printf("Ошибка ввода!");
    }    
    return result;
}

bool isTargetHit(float x, float y, float radius){
    // bool result = false;    
    // if ((x * x + y * y) < (radius * radius)){
    //     result = true;
    // }
    bool result = ((x * x + y * y) < (radius * radius)) ? true : false;
    return result;
}
