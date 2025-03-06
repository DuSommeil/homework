// Создать класс Окружность, член класса – R. 
// Предусмотреть в классе методы вычисления и вывода сведений о фигуре – площади, длины окружности. 
// Создать производный класс – Прямой цилиндр с высотой h, добавить в класс метод 
// определения объема фигуры, перегрузить методы расчета площади и вывода сведении о фигуре. 
// Написать программу, демонстрирующую работу с классом: дано X окружностей и М цилиндров, 
// найти окружность максимальной площади и средний объем цилиндров.

#include <iostream>
#include <cmath>

using namespace std;

class Circle
{
protected:
    double radius;

public:
    Circle(double r) : radius(r) {} // конструктор с параметром

    double Length() const //вычислиение длины окружности
    {
        return 2 * M_PI * radius;
    }

    virtual double Area() const //вычисление площади окружности
    {
        return M_PI * radius * radius;
    }

    virtual void Print() const //вывод информации окружности
    {
        cout << "Окружность с радиусом: " << radius << endl;
        cout << "Площадь: " << Area() << endl;
        cout << "Длина окружности: " << Length() << endl;
    }

    ~Circle(){}
};

class Cylinder : public Circle //производный класс цилиндр
{
private:
    double height;

public:
    Cylinder(double r, double h) : Circle(r), height(h) {}

    double Volume() const
    {
        return Area() * height; //вычисление объема
    }

    double Area() const
    {
        return 2 * M_PI * radius * (radius + height); // перегрузка метода для вычисления площади цилиндра (переопределили)
    }

    void Print() const //вывод значений окружности
    {
        cout << "Прямой цилиндр с высотой " << height << ", а радиусом " << radius << endl;
        cout << "Площадь: " << Area() << endl;
        cout << "Объем: " << Volume() << endl;
    }

    ~Cylinder(){}
};

int main()
{
    int X, M;
    cout << "Введите кол-во окружностей: ";
    cin >> X;
    cout << "Введите кол-во цилиндров: ";
    cin >> M;

    Circle* circles[X]; // массив указателей на объекты класса Circle
    Cylinder* cylinders[M]; // массив указателей на объекты класса Cylinder

    // вводим данные для окружностей
    for (int i = 0; i < X; i++)
    {
        double radius;
        cout << "Введите радиус окружности " << i + 1 << ": ";
        cin >> radius;
        circles[i] = new Circle(radius);
    }

    //ввод данных для цилиндров
    for (int i = 0; i < M; i++)
    {
        double radius, height;
        cout << "Введите радиус и высоту цилиндра " << i + 1 << ": ";
        cin >> radius >> height;
        cylinders[i] = new Cylinder(radius, height);
    }

    // поиск с максимальной плозадью
    double maxCircleArea = 0;
    int maxCircleIndex = -1;
    for (int i = 0; i < X; i++)
    {
        if (circles[i]->Area() > maxCircleArea)
        {
            maxCircleArea = circles[i]->Area();
            maxCircleIndex = i;
        }
    }

    // вывод окружности с максимальной площадью
    if (maxCircleIndex != -1)
    {
        cout << "\n\nОкружность с максимальной площадью является:\n";
        circles[maxCircleIndex]->Print();
    }

    // вычисление среднего объема цилиндров
    double totalVolume = 0;
    for (int i = 0; i < M; i++)
    {
        totalVolume += cylinders[i]->Volume();
    }
    double averageVolume;
    if (M > 0) 
    {
    averageVolume = totalVolume / M;
    }
    else 
    {
    averageVolume = 0;
    }

    cout << "\nСредний объем цилиндров равен: " << averageVolume << endl;

    for (int i = 0; i < X; i++)
    {
        delete circles[i]; 
    } // освобождаем память
    for (int i = 0; i < M; i++)
    {
        delete cylinders[i];
    } // освобождаем память

    return 0;
}
