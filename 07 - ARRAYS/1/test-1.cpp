#include <iostream>
#include <stdlib.h>
#include <time.h>

bool isDecreasing(int array[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        if (array[i] >= array[i - 1]) 
        {
            return false;
        }
    }
    return true;
}

bool canBecomeDecreasingByRemovingOne(int array[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        int prev = (i > 0) ? array[i - 1] : INT_MIN;
        int next = (i < n - 1) ? array[i + 1] : INT_MAX;

        if (next < prev) 
        {
            continue;
        }

        if (isDecreasing(array, i) && isDecreasing(array + i + 1, n - i - 1)) {
            return true;
        }
    }
    return false;
}

int main() 
{
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    srand(time(NULL));

    int array[n];
    std::cout << "Сгенерированный массив:\n";
    for (int i = 0; i < n; i++) 
    {
        array[i] = rand() % 30 + 1;
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    if (canBecomeDecreasingByRemovingOne(array, n)) {
        std::cout << "Можно удалить один элемент, чтобы массив стал убывающим.\n";
    } else {
        std::cout << "Нельзя удалить один элемент, чтобы массив стал убывающим.\n";
    }

    return 0;
}
