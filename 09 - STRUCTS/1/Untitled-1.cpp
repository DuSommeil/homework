#include <iostream>
#include <stdlib.h>
#include <math.h>

#define size 100

// используем typedef для облегчения написания программы, чтобы не писать struct и тд каждый раз а напрямую обращаться к dekart
typedef struct
{
    float x, y;
}
dekart; 


// аналогично
typedef struct
{
    float r, fi; // фи - радинаны, r > 0
}
polar;

// ф-ия преобразования из декартовых в полярные координаты
polar dp(dekart d) 
{
    polar p;
    p.r = sqrt(d.x * d.x + d.y * d.y);
    p.fi = atan2(d.y, d.x);
    return p;
}

// ф-ия преобразования из полярных в декартовые координаты
dekart pd(polar p)
{
    dekart d;
    d.x = p.r * cos(p.fi);
    d.y = p.r * sin(p.fi);
    return d;
}


// меню для выбора варианта
// используем воид т.к. нам ничего не нужно получать/возвращать, значения получаем уже в самом main'е программы
void show_menu() 
{
    printf("\nВыберите действие:\n");
    printf("1. Добавить точку в декартовых координатах\n");
    printf("2. Преобразовать точку из декартовых в полярные\n");
    printf("3. Преобразовать точку из полярных в декартовые\n");
    printf("4. Показать список точек\n");
    printf("5. Сортировать точки по расстоянию от начала координат\n");
    printf("6. Выйти\n");
    printf("\n");
    printf("Ваш выбор: ");
}

int sravnenie_dekart(const void *a, const void *b)
{
    dekart *da = (dekart*)a;
    dekart *db = (dekart*)b;

    float dista = sqrt(da -> x * da -> x + da -> y * da -> y);
    float distb = sqrt(db -> x * db -> x + db -> y * db -> y);

    return (dista > distb) - (dista < distb);
}

int main()
{
    dekart dekart_tochki[size];
    polar polar_tochki[size];

    int dekart_cnt = 0, polar_cnt = 0;
    
    // для выбора варианта из меню
    int choice = 0; // 0 для инициализации и во избежание возможных ошибок

    do
    {
        show_menu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                if (dekart_cnt >= size)
                {
                    printf("Список декартовых точек переполнен.\n");
                    break;
                }
                dekart d;
                printf("Введите x и y через пробел: ");
                scanf("%f %f", &d.x, &d.y);
                dekart_tochki[dekart_cnt++] = d; // добавляем точку в массив
                printf("Точка добавлена.\n");
                break;
            }
            case 2:
            {
                if (dekart_cnt == 0)
                {
                    printf("Список декартовых точек пуст.\n");
                    break;
                }
                printf("Введите индекс точки для преобразования (0 - %d): ", dekart_cnt - 1);
                int index;
                scanf("%d", &index);

                if (index >= 0 && index < dekart_cnt)
                {
                    if (polar_cnt >= size)
                    {
                        printf("Список полярных точек переполнен.\n");
                        break;
                    }
                    polar_tochki[polar_cnt++] = dp(dekart_tochki[index]);
                    printf("Точка преобразована в полярные координаты.\n");
                }
                else
                {
                    printf("Некорректный индекс.\n");
                }
                break;
            }
            case 3:
            {
                if (polar_cnt == 0) 
                {
                    printf("Список полярных точек пуст.\n");
                    break;
                }
                printf("Введите индекс точки для преобразования (0 - %d): ", polar_cnt - 1);
                int index;
                scanf("%d", &index);
                if (index >= 0 && index < polar_cnt) 
                {
                    if (dekart_cnt >= 100) 
                    {
                        printf("Список декартовых точек переполнен.\n");
                        break;
                    }
                    dekart_tochki[dekart_cnt++] = pd(polar_tochki[index]);
                    printf("Точка преобразована в декартовые координаты.\n");
                } 
                else 
                {
                    printf("Некорректный индекс.\n");
                }
                break;
            }
            case 4:
            {
                printf("\nДекартовые точки:\n");
                for (int i = 0; i < dekart_cnt; ++i) 
                {
                    printf("%d: (%.2f, %.2f)\n", i, dekart_tochki[i].x, dekart_tochki[i].y);
                }

                printf("\nПолярные точки:\n");
                for (int i = 0; i < polar_cnt; ++i) 
                {
                    printf("%d: (r=%.2f, fi=%.2f)\n", i, polar_tochki[i].r, polar_tochki[i].fi);
                }
                break;
            }
            case 5:
            {
                qsort(dekart_tochki, dekart_cnt, sizeof(dekart), sravnenie_dekart);
                printf("Точки отсортированы по расстоянию от начала координат.\n");
                break;
            }
            case 6:
            {
                printf("Выход из программы.\n");
                break;
            }
            default:
                printf("Некорректный выбор. Попробуйте снова.\n");
        }
    }
    while (choice != 6);

    return 0;
}
