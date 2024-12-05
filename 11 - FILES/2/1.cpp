// Дан текстовый файл, каждая строка которого изображает целое или вещественное число, 
// дополненное слева и справа несколькими пробелами 
// (вещественные числа имеют ненулевую дробную часть). 
// Вывести количество чисел с ненулевой дробной частью и их сумму. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;


int main() {
    FILE *file = fopen("/Users/maksimmakarov/Documents/с++/homework/11 - FILES/2/numbers.txt", "r");  // Открываем файл для чтения
    if (file == NULL) {  // Проверка на успешное открытие файла
        printf("Не удалось открыть файл, проверьте путь до файла или наличие файла!\n");
        return 1;  // Выход с ошибкой, если файл не открылся
    }

    char line[256];  // Массив для хранения каждой строки из файла
    int count = 0;    // Счётчик чисел с ненулевой дробной частью
    double sum = 0.0; // Сумма чисел с ненулевой дробной частью

    while (fgets(line, sizeof(line), file)) 
    {  // Чтение каждой строки из файла
        // Убираем ведущие и завершающие пробелы
        char *start = line;
        while (*start && isspace((unsigned char)*start)) 
        {
            start++;
        }
        char *end = start + strlen(start) - 1;
        while (end > start && isspace((unsigned char)*end)) 
        {
            end--;
        }
        *(end + 1) = '\0';  // Завершаем строку

        if (*start == '\0') 
        {
            continue;  // Пропускаем пустые строки
        }

        // Преобразуем строку в число
        double number = strtod(start, NULL);

        // Проверяем, есть ли у числа дробная часть
        if (number != (int)number) 
        {
            count++;    // Увеличиваем счётчик
            sum += number;  // Добавляем число к сумме
        }
    }

    fclose(file);  // Закрываем файл

    // Выводим результаты
    printf("Количество чисел с ненулевой дробной частью: %d\n", count);
    printf("Сумма чисел с ненулевой дробной частью: %.2f\n", sum);

    return 0;  // Завершаем программу
}

