#include <stdio.h>
#include <math.h>

// Пользователь вводит радиус через scanf.Нужно вычислить для указанного радиуса R:
//      1. Длину окружности. Формула 2 * Pi * R
//      2. Площадь круга. Формула Pi * R * R
//      3. Объем шара. Формула 4/3 * Pi * R * R * R
// Pi можно принять за 3.1415 либо использовать константу M_PI подключив #include <math.h>. 
// Результаты вывести в консоль через printf

int main(void){
    float radius = 0;
    float length = 0;
    float area = 0;
    float volume = 0;

    printf("Введите радиус.\n");
    scanf("%f", &radius);

    length = 2 * M_PI * radius;
    area = M_PI * radius * radius;
    volume = (float)4 / (float)3 * area * radius;

    printf("Длина окружности - %.2f\n", length);
    printf("Площадь окружности - %.2f\n", area);
    printf("Объем шара - %.2f\n", volume);
    return 0;
}