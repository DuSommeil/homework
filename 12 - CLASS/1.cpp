// Класс Электрический счетчик. При создании объекта указывается диапазон значении, 
// которые может отображать счетчик (при возникновении значения на 1 больше заданного максимального 
// счетчик "сбрасывается" на 0), единицы измерения. Для счетчика должны быть определены 
// операции увеличения значения на К и печать текущего значения.  
// В функции main проверить эти методы.

#include <iostream>
#include <string>

using namespace std;

class ElectricMeter
{
// задаем поля класса
    int minValue;          
    int maxValue;          
    string unit;
    int currentValue;      

public:
    // конструктор с параметрами
    ElectricMeter(int minVal, int maxVal, string unit): minValue(minVal), maxValue(maxVal), unit(unit), currentValue(minVal) {}

    // увеличиваем нынешнее значение на k учитывая переход за предел диапазона (если таковой случается)
    void increase(int k)
    {
        currentValue += k;
        if (currentValue > maxValue)
        {
            currentValue = minValue + (currentValue - maxValue - 1);
        }
    }

    // печать
    void printCurrentValue() const
    {
        cout << "Текущее значение: " << currentValue << " " << unit << endl;
    }
};

int main() 
{
    // создаем счетчик с минимальным и максимальным значением, а также единицой измерения (киловатт в час)
    ElectricMeter schet(0, 999, "kWh");

    // увеличиваем значение на 100
    schet.increase(100);
    schet.printCurrentValue();

    // увеличиваем значение на 900
    schet.increase(900);
    schet.printCurrentValue();  // перезапуск т.к больше 999

    // увеличиваем значение на 500
    schet.increase(500);
    schet.printCurrentValue(); // в итоге на выводе в конце будет 500

    return 0;
}