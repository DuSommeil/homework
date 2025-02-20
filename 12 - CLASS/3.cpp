// Класс квадрат, члены класса - длина стороны. Предусмотреть в 
// классе методы вычисления и вывода сведений о фигуре - диагональ, периметр, площадь. 
// В функции main продемонстрировать работу с этими классами: 
// дано N квадратов, найти квадрат с максимальной площадью

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

    //метод для вычисления диагонали квадртата
    double getDiag() const 
    {
        return sideLength * sqrt(2);
    }

    // метод для вычисления периметра квадрата
    double getPerimeter() const 
    {
        return 4 * sideLength;
    }

    // метод для вычисления площади квадрата
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

    // создаем массив указателей на Square, каждый элемент массива будет хранить в себе адрес объекта Square
    Square** squares = new Square*[N];

    // Ввод данных для N квадратов
    for (int i = 0; i < N; i++) 
    {
        double length;
        cout << "Введите длину стороны квадрата " << i + 1 << ": ";
        cin >> length;
        squares[i] = new Square(length); // создаем квадрат и сохраняем указатель в массив
    }

    // поиск квадрата с максимальной площадью
    double maxArea = 0;
    int maxIndex = -1; // индекс квадрата с максимальной площадью 

    for (int i = 0; i < N; i++) 
    {
        double area = squares[i]->getArea(); //задаем значение указателю
        if (area > maxArea) 
        {
            maxArea = area;
            maxIndex = i; // сохраняем индекс квадрата с максимальной площадью
        }
    }

    // вывод информации о квадрате с максимальной площадью
    if (maxIndex != -1) // т.е. если квадрат с максимальной площадью был найден
    {
        cout << "\nКвадрат с максимальной площадью: " << endl;
        squares[maxIndex]->printAll(); // 
    }
    else
    {
        cout << "Квадратов не найдено." << endl; // сообщение для ошибки
    }

    // освобождаем память
    for (int i = 0; i < N; i++) 
    {
        delete squares[i]; // удаляем каждый объект
    }
    delete[] squares; // удаляем массив указателей

    return 0;
}