// #include <iostream>
// #include <stdlib.h>
// #include <math.h>

// #define size 100

// // используем typedef для облегчения написания программы, чтобы не писать struct и тд каждый раз а напрямую обращаться к dekart
// typedef struct
// {
//     float x, y;
// }
// dekart; 


// // аналогично
// typedef struct
// {
//     float r, fi; // фи - радинаны, r > 0
// }
// polar;

// // ф-ия преобразования из декартовых в полярные координаты
// polar dp(dekart d) 
// {
//     polar p;
//     p.r = sqrt(d.x * d.x + d.y * d.y); // вычисление расстояния от начала координат
//     p.fi = atan2(d.y, d.x); // вычисление угла в радианах
//     return p;
// }

// // ф-ия преобразования из полярных в декартовые координаты
// dekart pd(polar p)
// {
//     dekart d;
//     d.x = p.r * cos(p.fi); // вычисление координаты x
//     d.y = p.r * sin(p.fi); // вычисление координаты y
//     return d;
// }


// // меню для выбора варианта
// // используем воид т.к. нам ничего не нужно получать/возвращать, значения получаем уже в самом main'е программы
// void show_menu() 
// {
//     printf("\nВыберите действие:\n");
//     printf("1. Добавить точку в декартовых координатах\n");
//     printf("2. Преобразовать точку из декартовых в полярные\n");
//     printf("3. Преобразовать точку из полярных в декартовые\n");
//     printf("4. Показать список точек\n");
//     printf("5. Сортировать точки по расстоянию от начала координат\n");
//     printf("6. Выйти\n");
//     printf("\n");
//     printf("Ваш выбор: ");
// }

// int sravnenie_dekart(const void *a, const void *b)
// {
//     dekart *da = (dekart*)a;
//     dekart *db = (dekart*)b;

//     float dista = sqrt(da -> x * da -> x + da -> y * da -> y);
//     float distb = sqrt(db -> x * db -> x + db -> y * db -> y);

//     return (dista > distb) - (dista < distb);
// }

// int main()
// {
//     dekart dekart_tochki[size];
//     polar polar_tochki[size];

//     int dekart_cnt = 0, polar_cnt = 0;
    
//     // для выбора варианта из меню
//     int choice = 0; // 0 для инициализации и во избежание возможных ошибок

//     do
//     {
//         show_menu();
//         scanf("%d", &choice);

//         switch(choice)
//         {
//             case 1:
//             {
//                 if (dekart_cnt >= size)
//                 {
//                     printf("Список декартовых точек переполнен.\n");
//                     break;
//                 }
//                 dekart d;
//                 printf("Введите x и y через пробел: ");
//                 if (scanf("%f %f", &d.x, &d.y) == 2)
//                 {
//                     dekart_tochki[dekart_cnt++] = d;
//                     printf("Точка добавлена. Всего точек: %d\n", dekart_cnt);
//                 }
//                 else
//                 {
//                     printf("Некорректный ввод. Попробуйте снова.\n");
//                     while (getchar() != '\n'); // Очистка буфера
//                 }
//                 break;
//             }
//             case 2:
//             {
//                 if (dekart_cnt == 0)
//                 {
//                     printf("Список декартовых точек пуст.\n");
//                     break;
//                 }
//                 printf("Введите индекс точки для преобразования (0 - %d): ", dekart_cnt - 1);
//                 int index;
//                 if (scanf("%d", &index) == 1 && index >= 0 && index < dekart_cnt)
//                 {
//                     if (polar_cnt >= size)
//                     {
//                         printf("Список полярных точек переполнен.\n");
//                         break;
//                     }
//                     polar_tochki[polar_cnt++] = dp(dekart_tochki[index]);
//                     printf("Точка преобразована в полярные координаты. Всего полярных точек: %d\n", polar_cnt);
//                 }
//                 else
//                 {
//                     printf("Некорректный индекс.\n");
//                     while (getchar() != '\n'); // Очистка буфера
//                 }
//                 break;
//             }
//             case 3:
//             {
//                 if (polar_cnt == 0) 
//                 {
//                     printf("Список полярных точек пуст.\n");
//                     break;
//                 }
//                 printf("Введите индекс точки для преобразования (0 - %d): ", polar_cnt - 1);
//                 int index;
//                 scanf("%d", &index);
//                 if (index >= 0 && index < polar_cnt) 
//                 {
//                     if (dekart_cnt >= 100) 
//                     {
//                         printf("Список декартовых точек переполнен.\n");
//                         break;
//                     }
//                     dekart_tochki[dekart_cnt++] = pd(polar_tochki[index]);
//                     printf("Точка преобразована в декартовые координаты.\n");
//                 } 
//                 else 
//                 {
//                     printf("Некорректный индекс.\n");
//                 }
//                 break;
//             }
//             case 4:
//             {
//                 printf("\nДекартовые точки:\n");
//                 for (int i = 0; i < dekart_cnt; ++i) 
//                 {
//                     printf("%d: (%.2f, %.2f)\n", i, dekart_tochki[i].x, dekart_tochki[i].y);
//                 }

//                 printf("\nПолярные точки:\n");
//                 for (int i = 0; i < polar_cnt; ++i) 
//                 {
//                     printf("%d: (r=%.2f, fi=%.2f)\n", i, polar_tochki[i].r, polar_tochki[i].fi);
//                 }
//                 break;
//             }
//             case 5:
//             {
//                 qsort(dekart_tochki, dekart_cnt, sizeof(dekart), sravnenie_dekart);
//                 printf("Точки отсортированы по расстоянию от начала координат.\n");
//                 break;
//             }
//             case 6:
//             {
//                 printf("Выход из программы.\n");
//                 break;
//             }
//             default:
//                 printf("Некорректный выбор. Попробуйте снова.\n");
//         }
//     }
//     while (choice != 6);

//     return 0;
// }

// Описать структурные типы:
// Декарт float x, y;
// Поляр с полями  float r, fi;
//                               {r>0, – π <fi< π)
// Описать функции: DP((d,р), преобразующую координат точки на плоскости из декартовых d в полярные р, и PD(р,d),  
// выполняющую обратное преобразование.
// Проверить работу  функции в головной программе.

#include <iostream>
#include <cmath>
#include <cstdlib> // Для функции qsort()

#define SIZE 100 // Максимальное количество точек

// Определение структуры для декартовых координат
typedef struct 
{
    float x, y; // x и y координаты
} dekart;

// Определение структуры для полярных координат
typedef struct 
{
    float r, fi; // r - радиус, fi - угол (в радианах)
} polar;

// Преобразование декартовых координат в полярные
polar dp(dekart d) 
{
    polar p;
    p.r = sqrt(d.x * d.x + d.y * d.y); // Расстояние от начала координат
    p.fi = atan2(d.y, d.x);            // Угол в радианах
    return p;
}

// Преобразование полярных координат в декартовые
dekart pd(polar p) 
{
    dekart d;
    d.x = p.r * cos(p.fi); // x = r * cos(fi)
    d.y = p.r * sin(p.fi); // y = r * sin(fi)
    return d;
}

// Печать меню
void show_menu() 
{
    std::cout << "\nВыберите действие:\n"
              << "1. Добавить точку в декартовых координатах\n"
              << "2. Преобразовать точку из декартовых в полярные\n"
              << "3. Преобразовать точку из полярных в декартовые\n"
              << "4. Показать список точек\n"
              << "5. Сортировать точки по расстоянию от начала координат\n"
              << "6. Выйти\n"
              << "Ваш выбор: ";
}

// Функция сравнения для сортировки декартовых точек по расстоянию
int compare_dekart(const void *a, const void *b) {
    const dekart *da = (const dekart *)a;
    const dekart *db = (const dekart *)b;

    // Вычисление расстояний от начала координат
    float dist_a = sqrt(da->x * da->x + da->y * da->y);
    float dist_b = sqrt(db->x * db->x + db->y * db->y);

    // Возвращаем -1, 0, или 1 в зависимости от сравнения
    return (dist_a > dist_b) - (dist_a < dist_b);
}

int main() 
{
    // Массивы для хранения точек
    dekart dekart_points[SIZE];
    polar polar_points[SIZE];

    // Количество точек в каждом массиве
    int dekart_count = 0, polar_count = 0;

    int choice = 0; // Выбор пользователя из меню

    do {
        show_menu();
        std::cin >> choice; // Ввод выбора пользователя

        switch (choice) {
            case 1: 
            { // Добавление точки в декартовых координатах
                if (dekart_count >= SIZE) {
                    std::cout << "Список декартовых точек переполнен.\n";
                    break;
                }
                dekart d;
                std::cout << "Введите x и y через пробел: ";
                if (std::cin >> d.x >> d.y) { // Проверка корректности ввода
                    dekart_points[dekart_count++] = d;
                    std::cout << "Точка добавлена. Всего точек: " << dekart_count << "\n";
                } else {
                    std::cout << "Некорректный ввод. Попробуйте снова.\n";
                    std::cin.clear(); // Сбрасываем состояние ошибки
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Пропускаем некорректный ввод
                }
                break;
            }
            case 2: 
            { // Преобразование из декартовых в полярные
                if (dekart_count == 0) {
                    std::cout << "Список декартовых точек пуст.\n";
                    break;
                }
                std::cout << "Введите индекс точки для преобразования (0 - " << dekart_count - 1 << "): ";
                int index;
                if (std::cin >> index && index >= 0 && index < dekart_count) {
                    if (polar_count >= SIZE) {
                        std::cout << "Список полярных точек переполнен.\n";
                        break;
                    }
                    polar_points[polar_count++] = dp(dekart_points[index]);
                    std::cout << "Точка преобразована в полярные координаты. Всего полярных точек: " << polar_count << "\n";
                } else {
                    std::cout << "Некорректный индекс. Попробуйте снова.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                break;
            }
            case 3: 
            { // Преобразование из полярных в декартовые
                if (polar_count == 0) {
                    std::cout << "Список полярных точек пуст.\n";
                    break;
                }
                std::cout << "Введите индекс точки для преобразования (0 - " << polar_count - 1 << "): ";
                int index;
                if (std::cin >> index && index >= 0 && index < polar_count) {
                    if (dekart_count >= SIZE) {
                        std::cout << "Список декартовых точек переполнен.\n";
                        break;
                    }
                    dekart_points[dekart_count++] = pd(polar_points[index]);
                    std::cout << "Точка преобразована в декартовые координаты. Всего декартовых точек: " << dekart_count << "\n";
                } else {
                    std::cout << "Некорректный индекс. Попробуйте снова.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                break;
            }
            case 4: 
            { // Показать список точек
                std::cout << "\nДекартовые точки:\n";
                for (int i = 0; i < dekart_count; ++i) {
                    std::cout << i << ": (" << dekart_points[i].x << ", " << dekart_points[i].y << ")\n";
                }

                std::cout << "\nПолярные точки:\n";
                for (int i = 0; i < polar_count; ++i) {
                    std::cout << i << ": (r=" << polar_points[i].r << ", fi=" << polar_points[i].fi << ")\n";
                }
                break;
            }
            case 5: 
            { // Сортировка точек по расстоянию
                qsort(dekart_points, dekart_count, sizeof(dekart), compare_dekart);
                std::cout << "Точки отсортированы по расстоянию от начала координат.\n";
                break;
            }
            case 6: 
            { // Выход
                std::cout << "Выход из программы.\n";
                break;
            }
            default:
                std::cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    } while (choice != 6);

    return 0;
}
