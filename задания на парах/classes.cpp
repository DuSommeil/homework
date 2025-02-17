#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

class Cylinder
{
    private:
    double radius;
    double height;

    public:
    Cylinder():radius(0), height(0){} // конструктор по умолчанию
    Cylinder(double r, double h):radius(r), height(h){} // конструктор с параметром
    Cylinder(Cylinder &cy):radius(cy.radius), height(cy.height){} // конструктор с копированием

    void set_field(double r, double h)
    {
        radius = r;
        height = h;
    }

    double get_radius() const
    {
        return radius;
    }

    double get_height() const 
    {
        return height;
    }

    double base_square() const 
    {
        return M_PI * (radius * radius);
    }

    double surface_square() const
    {
        return 2 * M_PI * radius * (height + radius);
    }

    double volume() const
    {
        return M_PI * (radius * radius) * height;
    }

    void output() const 
    {
        cout << "Радиус равен: " << radius << endl;
        cout << "Высота равна: " << height << endl;
        cout << "Площадь основания равна: " << base_square() << endl;
        cout << "Площадь поверхности равна: " << surface_square() << endl;
        cout << "Объем равен: " << volume() << endl;
    }

    ~Cylinder()
    {
        cout << "Деструктор вызван" << endl;
    }
};

int main()
{
    srand(time(NULL));

    Cylinder array[5];

    for (int i = 0; i < 5; i++)
    {
        double radius = 1 + (rand() % 100 / 10.0);
        double height = 1 + (rand() % 100 / 10.0);
        array[i].set_field(radius, height);
    }
    
    Cylinder *biggestVolume = &array[0];
    for (int i = 0; i < 5; i++)
    {
        if (array[i].volume() > biggestVolume->volume())
        {
            biggestVolume = &array[i];
        }
    }

    Cylinder *smallestSurfaceSquare = &array[0];
    for (int i; i < 5; i++)
    {
        if (array[i].surface_square() < smallestSurfaceSquare->surface_square())
        {
            smallestSurfaceSquare = &array[i];
        }
    }

    cout << "Цилиндр с наибольшим объемом: " << endl;
    biggestVolume->output();
    cout << "\n" << endl;

    cout << "Цилиндр с наименьшей площадью поверхности: " << endl;
    smallestSurfaceSquare->output();
    cout << "\n" << endl;

    return 0;
}