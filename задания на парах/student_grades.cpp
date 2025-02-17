#include <iostream>
#include <string.h>
using namespace std;

class Student
{
    public:
    string LastName;
    string Initials;
    double Grades[5];

public:
    Student():LastName(""), Initials("")
    {
        for (double &Grade : Grades)
        {
            Grade = 0;  
        }
    }
    Student(string ln, string i, double gr[5]):LastName(ln), Initials(i)
    {
        for (int i = 0; i < 5; ++i)
        {
            Grades[i] = gr[i];
        }
    }
    bool is5() const 
    {
        for (double grade : Grades)
        {
            if (grade == 5) 
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
    }
    
    bool is3() const
    {
        for (double grade : Grades)
        {
            if (grade == 3)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    bool is2() const
    {
        int count = 0;
        for (double grade : Grades)
        {
            if (grade == 2)
            {
                ++count;
            }
            else
            {
                return count > 0;
            }
        }
    }

    bool isKicked() const
    {
        int count = 0;
        for (double grade : Grades)
        {
            if (grade == 2)
            {
                ++count;
            }
            else
            {
                return count > 1;
            }
        }
    }

    void print() const
    {
        cout << LastName << " " << Initials << " - Оценки: " << endl;
        for (double grade: Grades)
        {
            cout << grade << endl;
        }
        cout << endl;
    }
};

class StudentList
{
    Student Students[20];
    int size;

    public:
    StudentList() : size(0) {}

    void AddStudent()
    {
        if (size >= 20)
        {
            cout << "Невозможно добавить больше студентов." << endl;
            return;
        }

        string LastName, Initials;
        double Grades[5];

        cout << "Введите фамилию студента: " << endl;
        cin >> LastName;
        cout << "Введите инициалы студента: " << endl;
        cin >> Initials;
        cout << "Введите 5 оценок студента: " << endl;
        for (double grade : Grades)
        {
            cin >> grade;
        }

        Students[size++] = Student(LastName, Initials, Grades);
        cout << "Студент успешно добавлен!" << endl;
    }


    void EditStudent(int Index)
    {
        if (Index < 0 || Index >= size) 
        {
            cout << "Ошибка: некорректный индекс." << endl;
            return;
        }
    
    cout << "Редактирование информации о студенте " << Students[Index].LastName << ":" << endl;
    cout << "Введите новую фамилию:" << endl;
    cin >> Students[Index].LastName;
    cout << "Введите новые инициалы" << endl;
    cin >> Students[Index].Initials;
    cout << "Введите новые оценки:" << endl;

    for (double &grade : Students[Index].Grades)
    {
        cin >> grade;
    }
    cout << "Информация обновлена." << endl;
    }

    void PrintAllStudents() const
    {
        if (size == 0)
        {
            cout << "Список студентов пуст." << endl;
            return;
        }

        cout << "Список студентов: " << endl;
        for (int i = 0; i < size; ++i)
        {
            cout << i + 1 << ". ";
            Students[i].print();
        }
    }

    void Print5Grades() const
    {
        cout << "Студенты с оценкой 5: " << endl;
        for (int i = 0; i < size; ++i)
        {
            if (Students[i].is5())
            {
                Students[i].print();
            }
        }
    }

    void Print3Grades() const
    {
        cout << "Студенты с оценкой 3: " << endl;
        for (int i = 0; i < size; ++i)
        {
            if (Students[i].is3())
            {
                Students[i].print();
            }
        }
    }

    void Print2Grades() const
    {
        cout << "Студенты с оценкой 2 (но не более одной): " << endl;
        for (int i = 0; i < size; ++i)
        {
            if (Students[i].is2() && !Students[i].isKicked())
            {
                Students[i].print();
            }
        }
    }
    
};

int main()
{
    StudentList studentList;
    int choice;

    do
    {
        cout << "\nМеню" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Редактировать студента" << endl;
        cout << "3. Показать список всех студентов" << endl;
        cout << "4. Показать список студентов с 5" << endl;
        cout << "5. Показать список студентов с 3" << endl;
        cout << "6. Показать список студентов с 2 (не более одной)" << endl;
        cout << "7. Выход" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
                studentList.AddStudent();
                break;
            case 2:
                int index;
                cout << "Введите номер студента (с 1): " << endl;
                cin >> index;
                studentList.EditStudent(index - 1);
                break;
            case 3:
                studentList.PrintAllStudents();
                break;
            case 4:
                studentList.Print5Grades();
                break;
            case 5:
                studentList.Print3Grades();
                break;
            case 6:
                studentList.Print2Grades();
                break;
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Ошибка: неверный выбор." << endl;
        }
    }
    while (choice != 0);

    return 0;
}