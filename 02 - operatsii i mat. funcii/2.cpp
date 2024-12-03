#include <stdio.h>
#include <math.h>

int main() 
{
    double angle = 0.5;
    
    printf("Синус: %f\n", sin(angle));
    printf("Косинус: %f\n", cos(angle));
    printf("Тангенс: %f\n", tan(angle));

    double value = 4.0;
    
    printf("Квадратный корень: %f\n", sqrt(value));
    printf("Натуральный логарифм: %f\n", log(value));
    
    return 0;
}