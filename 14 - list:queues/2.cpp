// Дан указатель Р1 на первый элемент непустого двусвязного списка. 
// Продублировать в списке все элементы с нечетными номерами (новые элементы добавлять 
// перед существующими элементами с такими же значениями) и вывести указатель на 
// первый элемент преобразованного списка.

#include <iostream>

using namespace std;

template <typename T>
class doublelist 
{
private:
    struct node 
    {
        T data;
        node* prev;
        node* next;
        node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };

    node* head; // указатель на первый элемент списка

public:
    doublelist(): head(nullptr) {}

    ~doublelist() 
    {
        while (head) 
        {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // добавление элемента в конец списка
    void add(T value) 
    {
        node* new_node = new node(value);
        if (head == nullptr) 
        {
            head = new_node;
            cout << "добавлен первый элемент: " << head->data << "\n";
        } 
        else 
        {
            node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
            cout << "добавлен элемент: " << new_node->data << "\n";
        }
    }

    // дублирование элементов с нечетными номерами
    void dupl_odd_nodes() 
    {
        if (head == nullptr) 
        {
            cout << "список пуст. дублирование невозможно.\n";
            return;
        }

        node* current = head;
        int index = 1; // индекс текущего элемента (начинается с 1)

        cout << "\nначало дублирования элементов с нечетными номерами:\n";

        while (current != nullptr) 
        {
            if (index % 2 != 0) { // если индекс нечетный
                // создаем новый элемент с тем же значением
                node* new_node = new node(current->data);

                // вставляем новый элемент перед текущим
                new_node->next = current;
                new_node->prev = current->prev;

                if (current->prev != nullptr) 
                {
                    current->prev->next = new_node;
                } 
                else 
                {
                    head = new_node; // если текущий элемент был первым, обновляем head
                }

                current->prev = new_node;

                cout << "дублирован элемент с индексом " << index << ": " << new_node->data << "\n";
            }

            current = current->next;
            index++;
        }

        cout << "дублирование завершено.\n";
    }

    // вывод списка
    void print() const 
    {
        node* temp = head;
        if (temp == nullptr) 
        {
            cout << "список пуст.\n";
            return;
        }

        cout << "\nсписок: ";
        while (temp != nullptr) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // вывод указателя на первый элемент списка
    void print_first_element() const 
    {
        if (head == nullptr) 
        {
            cout << "список пуст. указатель на первый элемент: NULL\n";
        } 
        else 
        {
            cout << "указатель на первый элемент списка: " << head << ", значение: " << head->data << "\n";
        }
    }
};

int main() {
    doublelist<int> list;

    // добавляем элементы в список
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    // выводим список
    list.print();

    // выводим указатель на первый элемент
    list.print_first_element();

    // дублируем элементы с нечетными номерами
    list.dupl_odd_nodes();

    // выводим список после дублирования
    list.print();

    // выводим указатель на первый элемент после дублирования
    list.print_first_element();

    return 0;
}