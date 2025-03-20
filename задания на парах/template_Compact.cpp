#include <iostream>
using namespace std;


template <class X>
void Сompact(X *items, int &count, int first, int last) {
    if (first < 0 || last >= count || first > last) {
        cout << "Некорректные индексы." << endl;
        return;
    }
    
    int shift = last - first + 1;
    for (int i = first; i < count - shift; i++) {
        items[i] = items[i + shift];
    }
    
    for (int i = count - shift; i < count; i++) {
        items[i] = 0;
    }
    
    count -= shift;
}

template <class X>
void Print(X *items, int count) 
{
    for (int i = 0; i < count; i++) 
    {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Исходный массив: ";
    Print(array, size);
    cout << endl;

    Сompact(array, size, 4, 7);

    cout << "Массив после уплотнения: ";
    Print(array, size);
    cout << endl;

    return 0;
}