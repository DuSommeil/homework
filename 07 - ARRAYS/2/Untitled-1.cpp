#include <iostream>
#include <stdlib.h>
#include <time.h>

// Функция для нахождения индекса строки с максимальным количеством одинаковых элементов
int find_duple(int array[][30], int m, int n)
{
    int maximum_count = 0; // Максимальное количество повторяющихся элементов
    int index = -1;        // Индекс строки с максимальным количеством повторений

    for (int i = 0; i < m; i++) // Проход по строкам матрицы
    {
        int current_maximum = 0; // Максимум для текущей строки

        for (int j = 0; j < n; j++) // Проход по элементам строки
        {
            int count = 0; // Счётчик повторений для текущего элемента

            for (int f = 0; f < n; f++) // Сравнение с другими элементами строки
            {
                if (array[i][j] == array[i][f])
                { 
                    count++; 
                }
            }

            if (count > current_maximum) // Обновление локального максимума
            { 
                current_maximum = count; 
            }
        }

        // Обновление глобального максимума и индекса строки
        if (current_maximum > maximum_count)
        { 
            maximum_count = current_maximum;
            index = i; 
        }

        // Если текущий максимум равен глобальному, обновляем индекс на текущую строку
        if (current_maximum == maximum_count)
        { 
            index = i; 
        }
    }
    return index; // Возвращаем индекс строки
}

int main()
{
    int m, n; // Размеры матрицы
    
    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Ввод размеров матрицы
    printf("Введите кол-во строк (M):");
    scanf("%d", &m);
    printf("Введите кол-во столбцов (N):");
    scanf("%d", &n);

    int array[30][30]; // Матрица фиксированного размера 30x30

    // Заполнение матрицы случайными числами и её вывод
    printf("Матрица %d на %d:\n", m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = rand() % 30 + 1; // Случайные числа от 1 до 30
            printf("%4d ", array[i][j]);
        }
        printf("\n"); // Переход на новую строку
    }

    // Нахождение строки с максимальным числом повторений
    int row = find_duple(array, m, n);

    // Вывод результата
    if (row != -1)
    { 
        printf("Номер последней строки, содержащей макс. кол-во одинаковых элементов равен: %d\n", row + 1); 
    } 
    else 
    {
        return 0;
    }

    return 0;
}

