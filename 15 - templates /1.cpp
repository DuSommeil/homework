// Описать шаблонный класс Set для представления множества. Элементы множества хранить в динамической памяти 
// в виде односвязного списка. Повторяющиеся элементы в Set не заносятся.
// Для объектов класса Set определить операции проверка добавления элемента в множество (add), 
// удаление элемента (del), вхождения элемента (in), пересечение 3-х множеств.
// Продемонстрировать работу с шаблонным классом для разных типов информационных элементов.

#include <iostream>
using namespace std;

// шаблонный класс узла списка
template <typename T>
class Node 
{
public:
    T data;
    Node* next;
    
    Node(const T& value) : data(value), next(nullptr) {}
};

// шаблонный класс множества
template <typename T>
class Set 
{
private:
    Node<T>* head;
    int size;
    
    // проверка наличия элемента в множестве
    bool contains(const T& value) const 
    {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) 
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
public:
    // конструктор
    Set() : head(nullptr), size(0) {}
    
    // деструктор
    ~Set() 
    {
        clear();
    }
    
    // копирующий конструктор
    Set(const Set<T>& other) : head(nullptr), size(0) 
    {
        Node<T>* current = other.head;
        while (current != nullptr) 
        {
            add(current->data);
            current = current->next;
        }
    }
    
    // оператор присваивания
    Set<T>& operator=(const Set<T>& other) 
    {
        if (this != &other) 
        {
            clear();
            Node<T>* current = other.head;
            while (current != nullptr) 
            {
                add(current->data);
                current = current->next;
            }
        }
        return *this;
    }
    
    // очистка множества
    void clear() 
    {
        while (head != nullptr) 
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
    
    // добавление элемента (возвращает true, если элемент был добавлен)
    bool add(const T& value) 
    {
        if (contains(value)) 
        {
            return false;
        }
        
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        size++;
        return true;
    }
    
    // удаление элемента (возвращает true, если элемент был удален)
    bool del(const T& value) 
    {
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        
        while (current != nullptr) 
        {
            if (current->data == value) 
            {
                if (prev == nullptr) 
                {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                size--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }
    
    // проверка вхождения элемента
    bool in(const T& value) const 
    {
        return contains(value);
    }
    
    // пересечение трех множеств (статический метод)
    static Set<T> intersection(const Set<T>& set1, const Set<T>& set2, const Set<T>& set3) {
        Set<T> result;
        
        Node<T>* current = set1.head;
        while (current != nullptr) 
        {
            if (set2.in(current->data) && set3.in(current->data)) 
            {
                result.add(current->data);
            }
            current = current->next;
        }
        
        return result;
    }
    
    // получение размера множества
    int getSize() const 
    {
        return size;
    }
    
    // вывод множества
    void print() const 
    {
        Node<T>* current = head;
        cout << "{ ";
        while (current != nullptr) 
        {
            cout << current->data;
            if (current->next != nullptr) 
            {
                cout << ", ";
            }
            current = current->next;
        }
        cout << " }" << endl;
    }
};

// демонстрация работы с разными типами данных
int main() 
{
    // работа с целыми числами
    Set<int> intSet1;
    intSet1.add(1);
    intSet1.add(2);
    intSet1.add(3);
    intSet1.add(2); // дубликат не добавится
    
    Set<int> intSet2;
    intSet2.add(2);
    intSet2.add(3);
    intSet2.add(4);
    
    Set<int> intSet3;
    intSet3.add(3);
    intSet3.add(4);
    intSet3.add(5);
    
    cout << "Множество целых чисел 1: ";
    intSet1.print();
    cout << "Множество целых чисел 2: ";
    intSet2.print();
    cout << "Множество целых чисел 3: ";
    intSet3.print();
    
    Set<int> intIntersection = Set<int>::intersection(intSet1, intSet2, intSet3);
    cout << "Пересечение трех множеств целых чисел: ";
    intIntersection.print();
    
    // работа со строками
    Set<string> strSet1;
    strSet1.add("apple");
    strSet1.add("banana");
    strSet1.add("orange");
    
    Set<string> strSet2;
    strSet2.add("banana");
    strSet2.add("kiwi");
    strSet2.add("orange");
    
    Set<string> strSet3;
    strSet3.add("orange");
    strSet3.add("pear");
    strSet3.add("banana");
    
    cout << "\nМножество строк 1: ";
    strSet1.print();
    cout << "Множество строк 2: ";
    strSet2.print();
    cout << "Множество строк 3: ";
    strSet3.print();
    
    Set<string> strIntersection = Set<string>::intersection(strSet1, strSet2, strSet3);
    cout << "Пересечение трех множеств строк: ";
    strIntersection.print();
    
    // демонстрация других операций
    cout << "\nПроверка вхождения элементов в Множество 1:" << endl;
    
    cout << "Элемент 'apple': ";
    if (strSet1.in("apple")) 
    {
        cout << "присутствует";
    } else {
        cout << "отсутствует";
    }
    cout << endl;
    
    cout << "Элемент 'kiwi': ";
    if (strSet1.in("kiwi")) 
    {
        cout << "присутствует";
    } else {
        cout << "отсутствует";
    }
    cout << endl;
    
    cout << "Элемент 'orange': ";
    if (strSet1.in("orange")) 
    {
        cout << "присутствует";
    } else {
        cout << "отсутствует";
    }
    cout << endl;
    
    cout << "\nУдаление элемента 'banana' из Множества 1: ";
    strSet1.del("banana");
    strSet1.print();
    
    cout << "\nПовторная проверка вхождения после удаления:" << endl;
    cout << "Элемент 'banana': ";
    if (strSet1.in("banana")) 
    {
        cout << "присутствует";
    } else {
        cout << "отсутствует";
    }
    cout << endl;

    return 0;
}