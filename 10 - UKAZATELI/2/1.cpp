// 2. В динамической памяти находятся массивы А и В одинакового размера N. 
// Поменять местами их содержимое И вывести вначале элементы преобразованного массива А, а затем элементы 
// преобразованного массива В.

#include <iostream>
#include <stdlib.h>

int main() {
    int N;

    // Вводим размер массивов
    printf("Введите размер массивов N: ");
    scanf("%d", &N);

    // Выделяем память для массивов A и B
    int* A = (int*)malloc(N * sizeof(int));
    int* B = (int*)malloc(N * sizeof(int));

    if (A == NULL || B == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    // Вводим элементы для массива A
    printf("Введите элементы массива A:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Вводим элементы для массива B
    printf("Введите элементы массива B:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }

    // Меняем местами элементы массивов A и B
    for (int i = 0; i < N; i++) {
        int temp = A[i];
        A[i] = B[i];
        B[i] = temp;
    }

    // Выводим преобразованный массив A
    printf("Массив A после обмена:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Выводим преобразованный массив B
    printf("Массив B после обмена:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    // Освобождаем память
    free(A);
    free(B);

    return 0;
}
