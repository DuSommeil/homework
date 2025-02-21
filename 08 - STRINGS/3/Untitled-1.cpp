// #include <stdio.h>
// #include <string.h>

// #define SIZE 1000

// int main() {
//     char input[SIZE]; // Исходная строка
//     char even_chars[SIZE]; // Четные символы
//     char odd_chars[SIZE]; // Нечетные символы

//     int even_index = 0, odd_index = 0;

//     // Ввод строки
//     printf("Введите строку: ");
//     fgets(input, SIZE, stdin);

//     // Убираем символ новой строки, если он есть
//     size_t length = strlen(input);
//     if (input[length - 1] == '\n') {
//         input[length - 1] = '\0'; // Удаляем символ новой строки
//         length--; // Обновляем длину строки
//     }

//     // Разделяем символы на чётные и нечётные позиции
//     for (size_t i = 0; i < length; i++) {
//         if (i % 2 == 0) {
//             even_chars[even_index++] = input[i]; // Чётные позиции
//         } else {
//             odd_chars[odd_index++] = input[i]; // Нечётные позиции
//         }
//     }

//     // Выводим результат: сначала чётные, затем нечетные в обратном порядке
//     printf("Зашифрованная строка: %s%s\n", even_chars, odd_chars);

//     return 0;
// }
#include <stdio.h>
#include <algorithm>

#define SIZE 1000

int main() {
    char input[SIZE]; // Исходная строка
    char even_chars[SIZE]; // Четные символы
    char odd_chars[SIZE]; // Нечетные символы

    int even_index = 0, odd_index = 0;

    // Ввод строки
    printf("Введите строку: ");
    fgets(input, SIZE, stdin);

    // Определяем длину строки вручную
    int length = 0;
    while (input[length] != '\0' && length < SIZE) {
        length++;
    }

    // Убираем символ новой строки, если он есть
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0'; // Удаляем символ новой строки
        length--; // Обновляем длину строки
    }

    // Разделяем символы на чётные и нечётные позиции
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            even_chars[even_index++] = input[i]; // Чётные позиции
        } else {
            odd_chars[odd_index++] = input[i]; // Нечётные позиции
        }
    }

    // Завершаем строки чётных и нечётных символов
    even_chars[even_index] = '\0';
    odd_chars[odd_index] = '\0';

    std::reverse(even_chars, even_chars + even_index);

    // Выводим результат: сначала чётные, затем нечетные в обратном порядке
    printf("Зашифрованная строка: %s%s\n", odd_chars, even_chars);

    return 0;
}
