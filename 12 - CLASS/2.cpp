// Класс Ограниченный массив чисел, объектами 
// класса являются массивы чисел в динамической памяти размером от 2 до 100 элементов. 
// Предусмотреть следующие методы: конструктор для проверки и задания размерности массива; 
// если размерность массива больше 100, то создаётся массив размерности 100 и выдается уведомление;
// ввод элементов массива; поиск первого по порядку положительного числа и его индекса.
// В функции main проверить эти методы.

#include <iostream>
using namespace std;

class Array 
{
    int* array;  // указатель на массив в динамической памяти
    int size;

public:
    // обычный конструктор
    Array(int n):size(n), array(nullptr){}

    // метод для проверки и корректировки размерности
    void validateSize() 
    {
        if (size < 2)
        {
            size = 2;  // минимальный размер массива
            cout << "Размер слишком маленький. Установлен размер 2." << endl;
        } 
        else if (size > 100) 
        {
            size = 100; // максимальный размер массива
            cout << "Размер слишком большой. Установлен размер 100." << endl;
        }
        array = new int[size]; // выделение памяти под массив
    }

    // деструктор для освобождения памяти
    ~Array() { delete[] array; cout << "Деструктор вызван." << endl; }

    // ввод элементов массива
    void inputElements() 
    {
        cout << "Введите " << size << " элемента/ов массива:" << endl;
        for (int i = 0; i < size; i++) 
        {
            cin >> array[i];
        }
    }

    // метод для поиска первого положительного числа и его индекса
    void findFirstPositive() const 
    {
        for (int i = 0; i < size; i++) 
        {
            if (array[i] > 0) 
            {
                cout << "Первое положительное число: " << array[i] << ".\n" << "Его индекс: " << i  << ".\n" << "Его номер в массиве: " << i + 1 << "." << endl;
                return;
            }
        }
        cout << "Ни одного положительного числа не найдено." << endl;
    }

    // Метод для вывода массива (для проверки)
    void printArray() const 
    {
        cout << "Элементы массива ";
        for (int i = 0; i < size; i++) 
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // cоздаем объект массива с размером 5
    Array mas(5);

    // проверяем и изменяем размерность
    mas.validateSize();

    // вводим элементы массива
    mas.inputElements();

    // выводим массив для проверки
    mas.printArray();

    // ищем первое положительное число
    mas.findFirstPositive();

    // проверка с размером больше 100
    Array mas2(150); // размер еще 150
    mas2.validateSize();    // тут размер будет автоматически установлен на 100

    return 0;
}