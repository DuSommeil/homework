#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList 
{
private:
    struct Node 
    {
        T data;
        Node* prev;
        Node* next;
        
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    size_t size;
    
    void clear() 
    {
        while (head) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
    
public:
    // Конструктор по умолчанию
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    // Деструктор
    ~DoublyLinkedList() 
    {
        clear();
    }
    
    // Конструктор копирования
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr), size(0) 
    {
        Node* current = other.head;
        while (current) 
        {
            push_back(current->data);
            current = current->next;
        }
    }
    
    // Оператор присваивания (глубокое копирование)
    DoublyLinkedList& operator=(const DoublyLinkedList& other) 
    {
        if (this != &other) 
        {
            clear();
            Node* current = other.head;
            while (current) 
            {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }
    
    // Добавление в конец списка
    void push_back(const T& value) 
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    
    // Вывод указателей на начало и конец списка
    void printPointers() const 
    {
        cout << "Указатель на начало списка: " << head << endl;
        cout << "Указатель на конец списка: " << tail << endl;
    }
    
    // Вывод списка на экран
    void printList() const 
    {
        Node* current = head;
        cout << "Элементы списка (размер " << size << "): ";
        while (current) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() 
{
    // Создаем и заполняем первый список
    DoublyLinkedList<int> list1;

    // list1.push_back(15);
    // list1.push_back(25);
    // list1.push_back(30);

    // cout << "первый список: " << endl;
    // list1.printList();
    // list1.printPointers();

    // DoublyLinkedList<int> list2;
    // list2 = list1;

    // list2.push_back(25);
    // list2.push_back(40);
    // list2.push_back(51);

    // cout << "второй список: " << endl;
    // list2.printList();
    // list2.printPointers();

    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);
    
    cout << "Первый список:" << endl;
    list1.printList();
    list1.printPointers();
    
    DoublyLinkedList<int> list2;
    list2 = list1;
    
    cout << "\nВторой список (после копирования):" << endl;
    list2.printList();
    list2.printPointers();
    
    list1.push_back(40);
    
    cout << "\nПосле изменения первого списка:" << endl;
    cout << "Первый список:" << endl;
    list1.printList();
    
    cout << "Второй список:" << endl;
    list2.printList();
    
    return 0;
}