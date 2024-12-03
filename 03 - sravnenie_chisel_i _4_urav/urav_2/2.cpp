#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double alpha;
    cout << "Введите угол альфа (в радианах): \n";
    cin >> alpha;

    double func = 1 - 1/4*pow(sin(2*alpha), 2) + cos(2*alpha);

    cout << "y1 = " << func << endl;

    return 0;
}