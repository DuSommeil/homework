#include <iostream>
#include <string>

using namespace std;

class ElectricMeter
{
private:
    int minValue;          
    int maxValue;          
    string unit;
    int currentValue;      

public:
    // конструктор с параметрами
    ElectricMeter(int minVal, int maxVal, string unit): minValue(minVal), maxValue(maxVal), unit(unit), currentValue(minVal) {}

    // увеличиваем нынешнее значение на k учитывая переход за предел диапазона
    void increaseBy(int k)
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
    ElectricMeter meter(0, 999, "kWh");

    // увеличиваем значение на 100
    meter.increaseBy(100);
    meter.printCurrentValue();

    // увеличиваем значение на 900
    meter.increaseBy(900);
    meter.printCurrentValue();  // перезапус т.к больше 999

    // увеличиваем значение на 500
    meter.increaseBy(500);
    meter.printCurrentValue(); 

    return 0;
}