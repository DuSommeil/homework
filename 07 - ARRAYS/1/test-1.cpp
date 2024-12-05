#include <iostream>

// Функция для проверки, является ли массив убывающим
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

// Функция для проверки возможности удаления одного элемента
bool decreaseOne(int array[], int n) 
{
    // Пробуем удалить каждый элемент по очереди
    for (int i = 0; i < n; i++) 
    {
        // Создаем новый массив без элемента i
        int newArray[n - 1];
        for (int j = 0, k = 0; j < n; j++) 
        {
            if (j == i) 
            continue;  // Пропускаем элемент i
            newArray[k++] = array[j];
        }
        
        // Проверяем, является ли новый массив убывающим
        if (isDecreasing(newArray, n - 1)) 
        {
            return true;  // Если нашли, что можно удалить один элемент и массив убывающий
        }
    }
    return false;  // Если не нашли подходящего элемента
}

int main() {
    int array[] = {9, 5, 2, 3, 1};
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