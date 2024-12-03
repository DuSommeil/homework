#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double alpha;
    cout << "Введите угол альфа (в радианах): \n";
    cin >> alpha;

    double func = 2*pow(sin(3*M_PI - 2*alpha), 2) * pow(cos(5*M_PI + 2*alpha), 2);

    cout << "y1 = " << func << endl;

    return 0;
}