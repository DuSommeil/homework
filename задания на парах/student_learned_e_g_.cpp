#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Learner
{
    protected:
    string fullName;
    string sex;
    int age;

    public:
    Learner(const string& name, string s, int a):fullName(name), sex(s), age(a){}

    string getFullName() const { return fullName; }
    string getGender() const { return sex; }
    int getAge() const { return age; }

    virtual void read() 
    {
        cout << "Введите ФИО: ";
        getline(cin, fullName);
        cout << "Введите пол (M/Ж): ";
        cin >> sex;
        cout << "Введите возраст: ";
        cin >> age;
        cin.ignore();
    }

    virtual void print() const {
        cout << "ФИО: " << fullName << endl;
        cout << "Пол: " << sex << endl;
        cout << "Возраст: " << age << endl;
    }

    virtual ~Learner(){}
};

class Pupil : public Learner
{
    private:
    int classNumber;
    string classLetter;

    public:
    Pupil(const string& name, string s, int a, int cn, string cl) : Learner(name, s, a), classNumber(cn), classLetter(cl) {}

    int getClassNumber() const { return classNumber; }
    string getClassLetter() const { return classLetter; }

    void read()
    {
        Learner::read();
        cout << "Введите номер класса: ";
        cin >> classNumber;
        cout << "Введите букву класса: ";
        cin >> classLetter;
        cin.ignore();
    }

    void print() const
    {
        cout << " --- Школьник --- " << endl;
        Learner::print();
        cout << "Класс: " << classNumber << classLetter << endl;
    }

    virtual ~Pupil(){}
};

class Student : public Learner
{
    private:
    string faculty;
    string major;
    string groupNumber;

    public:
    Student(const string& name, string s, int a, const string& f, const string& m, const string gn): Learner(name, s, a), faculty(f), major(m), groupNumber(gn) {}

    void read()
    {
        Learner::read();
        cout << "Введите факультет: ";
        getline(cin, faculty);
        cout << "Введите специальность: ";
        getline(cin, major);
        cout << "Введите номер группы: ";
        getline(cin, groupNumber);
    }

    void print() const
    {
        cout << " --- Студент --- " << endl;
        Learner::print();
        cout << "Факультет: " << faculty << endl;
        cout << "Специальность: " << major << endl;
        cout << "Номер группы: " << groupNumber << endl;
    }

    virtual ~Student(){}
};

class GraduateStudent : public Learner
{
    private:
    string workName;
    string teacherName;

    public:

    GraduateStudent(const string& name, string s, int a, const string& w, const string& t): Learner(name, s, a), workName(w), teacherName(t) {}

    void read()
    {
        Learner::read();
        cout << "Введите научную работу: ";
        getline(cin, workName);
        cout << "Введите научного руководителя: ";
        getline(cin, teacherName);
    }

    void print() const 
    {
        cout << " --- Студент --- " << endl;
        Learner::print();
        cout << "Научная работа: " << workName << endl;
        cout << "Научный руководитель: " << teacherName << endl;
    }

    virtual ~GraduateStudent(){}
};

class Vector
{
    private:
    Learner** students;
    int memory;
    int size;

    void resize(int newMemory)
    {
        Learner** newStudents = new Learner*[newMemory];
        for (int i = 0; i < size; i++)
        {
            newStudents[i] = students[i];
        }
        delete[] students;
        students = newStudents;
        memory = newMemory;
    }

public:
    Vector() : students(nullptr), memory(0), size(0) {}

    void addStudent(Learner* student)
    {
        if (size >= memory)
        {
            int newCapacity = (memory == 0) ? 1 : memory * 2;
            resize(newCapacity);
        }
        students[size++] = student;
    }

    void viewStudents() const
    {
        for (int i = 0; i < size; i++)
        {
            students[i]->print();
            cout << endl;
        }
    }

    ~Vector()
    {
        for (int i = 0; i < size; i++)
        {
            delete students[i];
        }
        delete[] students;
    }
};

// class Vector
// {
//     private:
//     vector<Learner*> students;

//     public:
//     void addStudent(Learner* student)
//     {
//         students.push_back(student);
//     }

//     void viewStudents() const
//     {
//         for (size_t i = 0; i < students.size(); i++)
//         {
//             students[i]->print();
//             cout << endl;
//         }
//     }
    
//     ~Vector()
//     {
//         for (size_t i = 0; i < students.size(); i++)
//         {
//             delete students[i];
//         }
//     }
// };

int main()
{
    Vector Students;

    Students.addStudent(new Pupil("Бебра Б.Б.", "М", 16, 10, "В"));
    Students.addStudent(new Student("Макаров М.А.", "М", 18, "ОИКС", "Информационные системы и технологии", "ИС1-Б24"));
    Students.addStudent(new GraduateStudent("ААА А.А.", "Ж", 23, "Какая-то работа", "БББ Б.Б."));

    Students.viewStudents();

    return 0;
}