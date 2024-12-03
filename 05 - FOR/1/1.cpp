#include <stdio.h>
int main()

{
    int i, n;

    do
    {
        printf("Введите целое положительное число:\n");
        scanf("%i", &n);
    }
    while(n <= 0);

    for (i = 1; i <= n; i++)
        if ( n % i == 0)
            printf("Делитель введеного числа равен %i\n",i);
    return 0;
}