#include <iostream>
using namespace std;

class Date
{
    private:
    int Day;
    int Month;
    int Year;

    public:
    Date():Day(0), Month(0), Year(0){}
    Date(int d, int m, int y):Day(d),Month(m),Year(y){}
    Date(Date &dt):Day(dt.Day),Month(dt.Month),Year(dt.Year){}

    bool LeapYear()
    {
        if ((Year % 4 == 0) && (Year % 100 != 0) || (Year % 400 == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void GetDate()
    {
        cout << "Введите день: " << endl;
        cin >> Day;
        cout << "Введите месяц: " << endl;
        cin >> Month;
        cout << "Введите год: " << endl;
        cin >> Year;
    }

    void Output() const
    {
        cout << "День:" << Day << endl;
        cout << "Месяц:" << Month << endl;
        cout << "Год:" << Year << endl;
    }

    ~Date()
    {
        cout << "Деструктор вызван для объекта с годом " << Year << "." << endl;
    }
};

int main()
{
    Date date1(15, 2, 2007);
    Date date2(20, 2, 2020);
    Date date3(20, 8, 2016);
    Date date4(14, 9, 2005);
    Date date5(4, 4, 2014);

    cout << "Дата 1:" << endl;
    date1.Output();
    cout << "Високосный год: " << (date1.LeapYear() ? "Да" : "Нет") << endl << endl;

    cout << "Дата 2:" << endl;
    date2.Output();
    cout << "Високосный год: " << (date2.LeapYear() ? "Да" : "Нет") << endl << endl;

    cout << "Дата 3:" << endl;
    date3.Output();
    cout << "Високосный год: " << (date3.LeapYear() ? "Да" : "Нет") << endl << endl;

    cout << "Дата 4:" << endl;
    date4.Output();
    cout << "Високосный год: " << (date4.LeapYear() ? "Да" : "Нет") << endl << endl;

    cout << "Дата 5:" << endl;
    date5.Output();
    cout << "Високосный год: " << (date5.LeapYear() ? "Да" : "Нет") << endl << endl;

    Date UserDate;
    cout << "Введите свою дату: " << endl;
    UserDate.GetDate();
    cout << "Ваша дата:" << endl;
    UserDate.Output();
    cout << "Високосный год: " << (UserDate.LeapYear() ? "Да" : "Нет") << endl;

    return 0;
}