#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double alpha;
    cout << "Введите угол альфа (в радианах): \n";
    cin >> alpha;

    double func = 1/4 - (1/4 * sin(5/8*M_PI - 8*alpha));

    cout << "y1 = " << func << endl;

    return 0;
}