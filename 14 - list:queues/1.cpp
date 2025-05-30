// 1) Даны указатели P1 и Р2 на начало и конец непустой очереди. Извлекать из очереди элементы, 
// пока значение начального элемента очереди не станет четным, и выводить значения извлеченных 
// элементов (если очередь не содержит элементов с четными значениями, то извлечь все ее элементы). 
// Вывести также новые адреса начала и конца очереди (для пустой очереди дважды вывести NULL). 
// После извлечения элементов из очереди освобождать память, которую они занимали.

// #include <iostream>
// #include <queue> // подключаем заголовочный файл для работы с очередью

// using namespace std;

// int main()
// {
//     queue<int> q; 

//     q.push(9);
//     q.push(11);
//     q.push(2);
//     q.push(7);
//     q.push(3);
//     q.push(3);
//     q.push(7);
//     q.push(3);
//     q.push(6);

//     // извлекаем элементы из очереди, пока первый элемент не станет четным
//     while (!q.empty() && q.front() % 2 != 0)
//     {
//         cout << "Извлеченный элемент: " << q.front() << "\n"; // выводим значение
//         q.pop(); // удаляем элемент из очереди
//     }

//     // выводим новое состояние очереди
//     if (q.empty())
//     {
//         cout << "Очередь пуста. Начальный и конечный элементы: NULL\n";
//     }
//     else
//     {
//         cout << "Новый начальный элемент: " << q.front() << "\n";
//         cout << "Новый конечный элемент: " << q.back() << "\n";
//     }

//     return 0;
// }

#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class queue_p1p2
{
private:
    struct node
    {
        T data;
        node* next;
        node(T value) : data(value), next(nullptr) {}
    };
    node* p1; // указатель на начало очереди
    node* p2; // указатель на конец очереди

public:
    queue_p1p2() : p1(nullptr), p2(nullptr) {}

    ~queue_p1p2()
    {
        while (p1)
        {
            node* temp = p1;
            p1 = p1->next;
            delete temp;
        }
    }

    // добавление элемента в очередь
    void queue_add(T value)
    {
        node* temp = new node(value);
        if (p1 == nullptr)
        {
            p1 = temp; // если очередь пуста, новый элемент становится началом
        }
        else
        {
            p2->next = temp; // иначе добавляем элемент в конец
        }
        p2 = temp; // обновляем указатель на конец очереди
    }

    // извлечение элементов из очереди до первого четного элемента
    void queue_res()
    {
        // пока очередь не пуста и первый элемент нечетный
        while (p1 && p1->data % 2 != 0)
        {
            node* temp = p1; // сохраняем текущий начальный элемент
            cout << "Извлеченный элемент: " << temp->data << ", его адерс: " << temp << "\n"; // выводим его значение
            p1 = p1->next; // перемещаем начало очереди на следующий элемент
            delete temp; // освобождаем память
        }

        // обновляем p2, если очередь стала пустой
        if (p1 == nullptr)
        {
            p2 = nullptr;
        }

        // вывод нового состояния очереди
        if (p1 == nullptr)
        {
            cout << "Новый начальный элемент: NULL, новый конечный элемент: NULL\n";
        }
        else
        {
            cout << "\n\nНачало: " << p1->data << "\nАдрес в памяти: " << p1 << "\n\nКонец: " << p2->data << "\nАдрес в памяти: " << p2 << "\n";
        }
    }

    // проверка, пуста ли очередь
    bool emptyornot() const
    {
        return p1 == nullptr;
    }

    bool get_element(T value)
    {
        node* current = p1;

        while (current)
        {
            if (current->data == value)
            {
                cout << "элемент " << value << " найден в очереди" << endl;
                return true;
            }
            current = current->next;
            
        }
        cout << "элемент " << value << " не найден." << endl;
        return false;
    }
};

int main()
{
    queue_p1p2<int> q;
    q.queue_add(9);
    q.queue_add(11);
    q.queue_add(2);
    q.queue_add(7);
    q.queue_add(3);
    q.queue_add(3);
    q.queue_add(7);
    q.queue_add(3);
    q.queue_add(6);
    q.queue_res();

    q.get_element(12);

    return 0;
}