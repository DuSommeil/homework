#include <iostream>
#include <cmath>

using namespace std;

class Square 
{
    double sideLength; // длина стороны квадрата
public:
    //конструктор обычный
    Square():sideLength(0){}

    //конструктор с параметром
    Square(double length):sideLength(length){}

    //метод для вычисления диагонали
    double getDiag() const 
    {
        return sideLength * sqrt(2);
    }

    // метод для вычисления периметра
    double getPerimeter() const 
    {
        return 4 * sideLength;
    }

    // метод для вычисления площади
    double getArea() const 
    {
        return sideLength * sideLength;
    }

    // метод для вывода сведений о фигуре
    void printAll() const 
    {
        cout << "Квадрат со стороной: " << sideLength << endl;
        cout << "Диагональ: " << getDiag() << endl;
        cout << "Периметр: " << getPerimeter() << endl;
        cout << "Площадь: " << getArea() << endl;
    }

    // получаем длины стороны
    double getSideLength() const 
    {
        return sideLength;
    }
};

int main() 
{
    int N;
    cout << "Введите кол-во квадратов: ";
    cin >> N;

    // Создаем массив указателей на Square
    Square** squares = new Square*[N];

    // Ввод данных для N квадратов
    for (int i = 0; i < N; i++) 
    {
        double length;
        cout << "Введите длину стороны квадрата " << i + 1 << ": ";
        cin >> length;
        squares[i] = new Square(length); // Создаем квадрат и сохраняем указатель в массив
    }

    // Поиск квадрата с максимальной площадью
    double maxArea = 0;
    int maxIndex = -1; // Индекс квадрата с максимальной площадью

    for (int i = 0; i < N; i++) 
    {
        double area = squares[i]->getArea();
        if (area > maxArea) 
        {
            maxArea = area;
            maxIndex = i; // Сохраняем индекс квадрата с максимальной площадью
        }
    }

    // Вывод информации о квадрате с максимальной площадью
    if (maxIndex != -1) 
    {
        cout << "\nКвадрат с максимальной площадью: " << endl;
        squares[maxIndex]->printAll();
    }
    else
    {
        cout << "Квадратов не найдено." << endl;
    }

    // Освобождаем память
    for (int i = 0; i < N; i++) 
    {
        delete squares[i]; // Удаляем каждый объект
    }
    delete[] squares; // Удаляем массив указателей

    return 0;
}