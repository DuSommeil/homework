#include <iostream>

int main() 
{
    int n;
    
    printf("Введите значение n от 2 до 25 (включительно):");
    scanf("%d", &n);
    
    if (n > 1 && n < 26) {
        for (int i = 0; i < n; i++) 
        {
            printf("%c", 'A' + i); // передвигаемся на кол-во символов i по таблице кодов ascii
        }
        printf("\n");
    } 
    else 
    {
        printf("Число n должно быть в пределах от 2 до 25\n");
    }
    return 0;
}