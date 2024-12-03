#include <stdio.h>

int main()

{
    int x, y, a, b;
    
    printf(" Введите верхнюю границу диапазона функции 'y = x²+1':");
    scanf("%i", &b);
    printf(" Введите нижнюю границу диапазона функции 'y = x²+1':");
    scanf("%i", &a);

    printf("------------------\n");
    printf("| X | Y | \n");
    printf("------------------\n");

    for (x = a; x <= b; x++)
    {
        y = x * x + 1;

        printf("| %i | %i |\n", x, x*x + 1);
        printf("------------------\n");    
    }
    return 0;
}