#include <stdio.h>
#include <string.h>

#define size 1000

int main() 
{
    char line[size];  // строка для ввода
    printf("Введите строку: ");
    fgets(line, sizeof(line), stdin);


    int length = strlen(line);  // длина строки

    if (line[length - 1] == '\n') 
    {
        line[length - 1] = '\0';  // заменяем '\n' на конец строки, потому что fgets добавляет \n в конце строки, из-за чего в выводе четные и нечетные символы будут находиться на разных строках консоли
        length--;  // уменьшаем длину строки
    }

    char even_line[size], odd_line[size];  // массивы для четных и нечетных позиций
    int even_index = 0, odd_index = 0;

    for (int i = 0; i < length; i++) // разделяем символы на четные и нечетные позиции
    {
        if (i % 2 == 0) 
        {
            even_line[even_index++] = line[i]; // четные позиции
        } 
        else 
        { 
            odd_line[odd_index++] = line[i]; // нечетные позиции
        }
    }

    even_line[even_index] = '\0';  // завершаем строку для четных символов
    odd_line[odd_index] = '\0';    // завершаем строку для нечетных символов

    // выводим результат: четные символы и нечетные символы
    printf("Зашифрованная строка: %s", even_line);
    printf("%s", odd_line);
    
    return 0;
}
