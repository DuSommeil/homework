#include <stdio.h>

int main()
{
    int a, b, c, max1, max2, max3;
    printf ("Введите 1 число: ");
    scanf ("%i", &a);
    printf ("Введите 2 число: ");
    scanf ("%i", &b);
    printf ("Введите 3 число: ");
    scanf ("%i", &c);

    while (a == b && b == c && a == c)
    {
        printf("Числа одинаковы!!!!!!!\n");
        printf ("Введите 1 число: ");
        scanf ("%i", &a);
        printf ("Введите 2 число: ");
        scanf ("%i", &b);
        printf ("Введите 3 число: ");
        scanf ("%i", &c);
    }
    if (a > b)
    {
        max1 = a;
        max2 = b;
    }
    else
    {
        max1 = b;
        max2 = a;
    }
    if ( max1 > c )
    {
        if ( max2 > c)
        {
            max3 = c;
        }
        else
        {
            max3 = max2;
            max2 = c;
        }
    }
    else
    {
        max3 = max2;
        max2 = max1;
        max1 = c;
    }
    printf("max1 = %i, max2 = %i, max3 = %i. \n", &max1, &max2, &max3);
    return 0;
}