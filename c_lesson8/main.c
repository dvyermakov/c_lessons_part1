#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Направление сортировки
#define ASC     1       // сортировка по возрастанию 
#define DESC    0       // сортировка по убыванию

// Реализовать алгоритм сортировки массива(любой на ваше усмотрение)
// И продемонстрировать его работу.
// Исходные данные для массива либо вводятся вручную, либо берутся случайные значения через rand()

void arrayUserFill(int array[], int size); // заполнение массива пользователем
void arrayRandomFill(int array[], int size); // заполнение массива случайными значениями
void arrayRowPrint(int array[], int size); // вывод массива в строку
void arraySortBubble(int array[], int size, int direction); // сортировка пузырьком (direction - направление сортировки [ASC | DESC])
void swapElements(int* a, int* b); // обмен элементов

int main(void){
    const int arraySize = 10;
    int array[arraySize];
    // printf("Введите %d элементов массива\n", arraySize);
    // arrayUserFill(array, arraySize);   
    arrayRandomFill(array, arraySize); 
    printf("Введенный массив\n");
    arrayRowPrint(array, arraySize);
    arraySortBubble(array, arraySize, DESC);
    printf("Массив отсортированный по убыванию\n");
    arrayRowPrint(array, arraySize);
    arraySortBubble(array, arraySize, ASC);
    printf("Массив отсортированный по возрастанию.\n");
    arrayRowPrint(array, arraySize);
    return 0;
}

void arrayUserFill(int array[], int size){
    for (int i = 0; i < size; ++i){
        scanf("%d", &array[i]);
    }
}

void arrayRandomFill(int array[], int size){
    srand(time(NULL));
    for (int i = 0; i < size; ++i){
        array[i] = rand() % 100 - 50;
    }
}

void arrayRowPrint(int array[], int size){
    for (int i = 0; i < size; ++i){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void arraySortBubble(int array[], int size, int direction){
    bool flag;
    for (int i = 1; i < size; ++i){
        flag = false;
        for (int j = 0; j < size - i; ++j){
            if (direction == DESC){
                if (array[j] < array[j + 1]){
                    swapElements(&array[j], &array[j + 1]);
                    flag = true;
                }
            }
            if (direction == ASC){
                if (array[j] > array[j + 1]){
                    swapElements(&array[j], &array[j + 1]);
                    flag = true;
                }
            }                
        }
        if (flag == false) break;
    }
}

void swapElements(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}