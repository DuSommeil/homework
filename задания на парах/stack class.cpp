#include <iostream>

using namespace std;

template <class T>
class stacks
{
    struct node
    {
        T value;
        node* prev;
    };

    node* top;
    int stack_size;

public:
    stacks() : top(NULL), stack_size(0) {}

    void push(T key)
    {
        node* newNode = new node;
        newNode->value = key;
        newNode->prev = top;
        top = newNode;
        stack_size++;
    }

    T pop()
    {
        if (top == NULL)
        {
            cerr << "Stack underflow!" << endl;
            return -1;
        }
        T val = top->value;
        node* temp = top;
        top = top->prev;
        delete temp;
        stack_size--;
        return val;
    }

    int size()
    {
        return stack_size;
    }

    void print()
    {
        node* current = top;
        while (current)
        {
            cout << current->value << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~stacks()
    {
        while (top)
        {
            node* temp = top;
            top = top->prev;
            delete temp;
        }
        cout << "Destructor called" << endl;
    }
};

int main()
{
    stacks<int> stk;
    cout << "Popping from empty stack: " << stk.pop() << endl;

    for (int i = 10; i > 0; i--)
    {
        stk.push(i);
    }
    
    stk.print();

    cout << "Popped elements: " << stk.pop() << ", " << stk.pop() << endl;

    stk.print();


    cout << "_____\n";

    stacks<char> stk;
    cout << "Popping from empty stack: " << stk.pop() << endl;

    for (int i = 50; i > 0; i--)
    {
        stk.push(i);
    }
    
    stk.print();

    cout << "Popped elements: " << stk.pop() << ", " << stk.pop() << endl;

    stk.print();

    return 0;
}