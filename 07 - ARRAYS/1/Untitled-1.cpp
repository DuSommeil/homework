#include <iostream>
#include <stdlib.h>
#include <time.h>

int decrease(int array[], int n)
{
    for (int i = 0; i < n; i++) // проверка является ли массив убывающим
    {
        if (array[i] >= array[i - 1])
        { return 0; }
    } return 1; }

int remove(int array[], int n) // проверяем возможность удаления одного элемента массива
{
    int count = 0; // колво нарушений
    int position = -1; //  позиция первого нарушения

    for (int i = 0; i < n; i++) // находим место первого нарушения 
    {
        if (array[i] >= array[i - 1])
        {
            count++;
            position = i;
            
            if (count > 1)
            { return 0; }
        }
    }

    if (count == 0) // нет нарушений - массив убывающим
    { return 1; }

    // если есть нарушение - то пробуем удалить элемент на позиции position или position - 1

    if (decrease(array, position) && decrease(array + position + 1, n - position - 1));
    { return 1; }
    if (decrease(array, position - 1) && decrease(array + position, n - position - 1));
    { return 1; }

    return 0;
}

int main ()
{
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    srand(time(NULL));

    int array[n];
    printf("Сгенерированный массив:\n");
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 30 + 1;
        printf("%d ", array[i]);
    } 
    printf("\n");

    if (remove(array, n)) // проверка, можем ли убрать один элемент массива
    {
        printf("Можно удалить один элемент, чтобы массив стал убывающим.\n");
    } 
    else 
    {
        printf("Нельзя удалить один элемент, чтобы массив стал убывающим.\n");
    }

    return 0;
}