#include <iostream>
#include <cmath>

using namespace std;

class Circle
{
protected:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double Length() const
    {
        return 2 * M_PI * radius;
    }

    virtual double Area() const
    {
        return M_PI * radius * radius;
    }

    virtual void Print() const
    {
        cout << "Окружность с радиусом: " << radius << endl;
        cout << "Площадь: " << Area() << endl;
        cout << "Длина окружности: " << Length() << endl;
    }

    ~Circle(){}
};

class Cylinder : public Circle
{
private:
    double height;

public:
    Cylinder(double r, double h) : Circle(r), height(h) {}

    double Volume() const
    {
        return Area() * height;
    }

    double Area() const
    {
        return 2 * M_PI * radius * (radius + height); // перегрузка метода для вычисления площади цилиндра
    }

    void Print() const
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

    Circle* circles[X];
    Cylinder* cylinders[M];

    for (int i = 0; i < X; i++)
    {
        double radius;
        cout << "Введите радиус окружности " << i + 1 << ": ";
        cin >> radius;
        circles[i] = new Circle(radius);
    }

    for (int i = 0; i < M; i++)
    {
        double radius, height;
        cout << "Введите радиус и высоту цилиндра " << i + 1 << ": ";
        cin >> radius >> height;
        cylinders[i] = new Cylinder(radius, height);
    }

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

    if (maxCircleIndex != -1)
    {
        cout << "\n\nОкружность с максимальной площадью является:\n";
        circles[maxCircleIndex]->Print();
    }
    
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
    }
    for (int i = 0; i < M; i++)
    {
        delete cylinders[i];
    }

    return 0;
}
