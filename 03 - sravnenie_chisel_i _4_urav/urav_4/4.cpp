#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double alpha;
    cout << "Введите угол альфа (в радианах): \n";
    cin >> alpha;

    double func = pow(cos(alpha), 2) + pow(cos(alpha), 4);

    cout << "y1 = " << func << endl;

    return 0;
}