// Найти в файле строку, содержащую самую раннюю весеннюю дату. 
// Если даты с требуемым временем года в файле отсутствуют, 
// то вывести сообщение об этом.

#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int date_spring(int month)
{
    return (month == 3) || (month == 4) || (month == 5);
}
void parser(FILE *file, int *first_day, int *first_month, int *first_year, int *found_date)
{
    char line[MAX_LENGTH];

    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = 0;

        int day, month, year;
        if (sscanf(line, "%d/%d/%d", &day, &month, &year) == 3)
        {
            if(date_spring(month))
            {
                if (!*found_date || (year < *first_year) || (year == *first_year && month < *first_month) || (year == *first_year && month == *first_month && day < *first_day))
                {
                    *first_day = day;
                    *first_month = month;
                    *first_year = year;
                    *found_date = 1;
                }
            }
        }
    }
}

int main()
{
    FILE *file = fopen("/Users/maksimmakarov/Documents/с++/homework/11 - FILES/1/dates.txt", "r");
    if (!file)
    {
        printf("Не удалось открыть файл./n");
        return 1;
    }
    int first_day = 32, first_month = 0, first_year = 0, found_date = 0;

    parser(file, &first_day, &first_month, &first_year, &found_date);

    if (found_date)
    {
        printf("Самая ранняя весенняя дата равна: %02d/%02d/%d\n", first_day, first_month, first_year);
    } else {
        printf("В этом файле нет весенних дат.\n");
    }

    fclose(file);
    return 0;
}
