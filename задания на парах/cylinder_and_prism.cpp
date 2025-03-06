#include <iostream>
#include <cmath>

using namespace std;

class Area
{
    protected:
    double radius;

    public:
    Area(double r): radius(r) {}

    double getArea() const
    {
        return M_PI * radius * radius;
    }
    double getLength() const
    {
        return 2 * M_PI * radius;
    }
    double getRadius() const
    {
        return radius;
    }
};
class Cylinder: public Area
{
    private:
    double height;

    public:
    Cylinder(double r, double h): Area(r), height(h) {}

    double getVolume() const 
    {
        return getArea() * height;
    }

    double getSurface () const 
    {
        return 2 * getArea() + getLength() * height;
    }

    double getHeight() const
    {
        return height;
    }
};

int main()
{
    Cylinder c1(3.5, 4);
    Cylinder c2(6, 5);
    Cylinder c3(2, 9);

    Cylinder maxCylinder = c1;

    if (c2.getVolume() > maxCylinder.getVolume())
    {
        maxCylinder = c2;
    }
    if (c3.getVolume() > maxCylinder.getVolume())
    {
        maxCylinder = c3;
    }

    cout << "Цилиндр с наибольшим объемом:\n" << endl;
    cout << "Радиус: " << maxCylinder.getRadius() << endl;
    cout << "Высота: " << maxCylinder.getHeight() << endl;
    cout << "Объем: " << maxCylinder.getArea() << endl;
}