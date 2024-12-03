#include <stdio.h>
#include <iostream>

using namespace std;
 
int main ()
{
    double x;
    double s;

    printf ("Введите последовательность через пробел:\n");
    
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        s += x;

        cout<<"Cреднее арифметическое:\n"<<s / (i + 1)<<endl;
    }
    return 0;

}