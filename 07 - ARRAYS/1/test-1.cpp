#include <iostream>

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

bool decreaseOne(int array[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        // Определяем предыдущий и следующий элементы массива
    int prev;
    if (i > 0) {
        prev = array[i - 1];
    } else {
        prev = INT_MIN;
    }
    
    int next;
    if (i < n - 1) 
    {
        next = array[i + 1];
    } else {
        next = INT_MAX;
    }

        if (next < prev) 
        {
            continue;
        }

        if (isDecreasing(array, i) && isDecreasing(array + i + 1, n - i - 1)) 
        {
            return true;
        }
    }
    return false;
}

int main() 
{
    int array[] = {9, 8, 2, 6, 3};
    int n = sizeof(array) / sizeof(array[0]);

    std::cout << "Массив:\n";
    for (int i = 0; i < n; i++) 
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    if (decreaseOne(array, n)) 
    {
        std::cout << "Можно удалить один элемент, чтобы массив стал убывающим.\n";
    } else {
        std::cout << "Нельзя удалить один элемент, чтобы массив стал убывающим.\n";
    }

    return 0;
}

