    #include <iostream>
using namespace std;

template <class X>
    void Bubble(X *items, int count)
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - 1; j++)
            {
                if (items[j] > items[j + 1])
                {
                    swap(items[j], items[j + 1]);
                }
            }
        }
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
    int array[] = {15, 51, 515, 55, 11};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Исходный массив: ";
    Print(array, size);
    cout << endl;

    Bubble(array, size);

    cout << "Отсортированный массив: ";
    Print(array, size);
    cout << endl;

    return 0;
}