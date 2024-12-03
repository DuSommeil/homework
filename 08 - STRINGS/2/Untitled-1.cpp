#include <stdio.h>
#include <string.h>

#define size 1000

int main() 
{
    printf("Введите строку: \n");
    char str[size];  // массив строки
    
    // получаем строку
    if (fgets(str, sizeof(str), stdin) == NULL) 
    {
        printf("Ошибка ввода!\n");
        return 0;  // завершение программы в случае ошибки
    }

    int max_len = 0, current_len = 0;

    // проходим по строке в цикле
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] != ' ' && str[i] != '\n') 
        {
            current_len++;  // увеличиваем длину текущего слова
        } 
        else 
        {
            if (current_len > max_len) 
            {
                max_len = current_len;  // обновляем максимальную длину
            }
            current_len = 0;  // сбрасываем длину
        }
    }

    // проверяем длину слова в конце строки
    if (current_len > max_len) 
    {
        max_len = current_len;
    }

    printf("Максимальная длина слова в строке: %d\n", max_len);

    return 0;
}