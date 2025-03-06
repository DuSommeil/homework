#include <iostream>

using namespace std;

class Array
{
    private:
    int *link
    size_t max_size
    size_t current_size

    Array(size_t max_size = 10): max_size(max_size), current_size(0)
    {
        link = new int[max_size];
    }

    Array(const Array& arr): max_size(arr.max_size), current_size(arr.current_size)
    {
        link = new int[max_size];
        for (size_t i = 0; i < current_size; i++)
        {
            link[i] = arr.link[i]
        }
    }

    ~Array() 
    {
        delete[] link;
        cout << "Деструктор вызван." << endl;
    }

    size_t size() const
    {
        return current_size;
    }

    void print() const
    {
        for (size_t i = 0; i < current_size; i++)
        {
            cout << link[i] << " ";
        }
        cout << endl;
    }

    int& operator[](size_t index)
    {
        if (index >= current_size)
        {
            cout << "Выход за границу массива." << endl;
        }
        return *this;

        link[current_size++] = value;
        return *this;

    const int& operator[](size_t index) const
    {
        if (index >= current_size)
        {
            cout << "Выход за границу массива." << endl;
            int error_value = -1;
            return error_value;
        }
        return link[index];
    }
    }

    Array& operator=(const Array& arr)
    {
        if (this == &arr)
        {
            return *this;
        }
        
        delete[] data;

        max_size = arr.max_size;
        current_size = arr.current_size;
        link = new int[max_size];
        
        for (size_t i = 0; i < current_size; i++)
        {
            link[i] = arr.link[i]
        }
        return *this;
    }
};

int main()
{
    Array arr(5)

    arr + 1 + 2 + 5;
    arr.print();

    arr + 6 + 3 + 4;
    arr.print();

    arr + 51;

    cout << "arr[2]" << arr[2] << endl;
    cout << "arr[10]" << arr[10] << endl;
}