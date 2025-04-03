#include <iostream>
using namespace std;

// класс для узла дерева
class Node 
{
public:
    int value;      // значение узла
    Node* left;     // левый потомок
    Node* right;    // правый потомок

    // конструктор узла
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// класс для бинарного дерева поиска
class BinarySearchTree 
{
private:
    Node* root;  // корень дерева

    // рекурсивная функция для добавления узла
    void addNode(Node*& node, int value) 
    {
        if (node == nullptr) 
        {
            node = new Node(value);  // если узел пустой, создаем новый
        } 
        else if (value < node->value) 
        {
            addNode(node->left, value);  // идем в левое поддерево
        } 
        else 
        {
            addNode(node->right, value);  // идем в правое поддерево
        }
    }

    // рекурсивная функция для удаления узла
    Node* deleteNode(Node* node, int value) 
    {
        if (node == nullptr) 
        {
            return node;  // если узел пустой, ничего не делаем
        }

        // ищем узел для удаления
        if (value < node->value) 
        {
            node->left = deleteNode(node->left, value);  // идем в левое поддерево
        } 
        else if (value > node->value) 
        {
            node->right = deleteNode(node->right, value);  // идем в правое поддерево
        } 
        else 
        {
            // узел найден

            // узел с одним или без потомков
            if (node->left == nullptr) 
            {
                Node* temp = node->right;
                delete node;  // удаляем текущий узел
                return temp;
            } 
            else if (node->right == nullptr) 
            {
                Node* temp = node->left;
                delete node;  // удаляем текущий узел
                return temp;
            }

            // узел с двумя потомками: получаем наименьший узел из правого поддерева
            Node* temp = findMin(node->right);  // получаем минимальный узел из правого поддерева
            node->value = temp->value;  // заменяем значение текущего узла на минимальное значение из правого поддерева
            node->right = deleteNode(node->right, temp->value);  // удаляем минимальный узел из правого поддерева
        }
        return node;
    }

    // функция для нахождения минимального элемента в поддереве
    Node* findMin(Node* node) 
    {
        while (node->left != nullptr) 
        {
            node = node->left;
        }
        return node;
    }

    // функция для вывода дерева в виде левой ветви
    void printLeftBranch(Node* node)
    {
        if (node != nullptr) 
        {
            cout << node->value << " ";  // выводим текущий узел
            printLeftBranch(node->left);  // рекурсивно идем по левому поддереву
        }
    }

    // функция для вывода дерева в виде правой ветви
    void printRightBranch(Node* node)
    {
        if (node != nullptr) 
        {
            cout << node->value << " ";  // выводим текущий узел
            printRightBranch(node->right);  // рекурсивно идем по правому поддереву
        }
    }

    // рекурсивная функция для вывода дерева
    void printInOrder(Node* node) 
    {
        if (node != nullptr) 
        {
            printInOrder(node->left);  // выводим левое поддерево
            cout << node->value << " ";  // выводим текущий узел
            printInOrder(node->right);  // выводим правое поддерево
        }
    }

    // рекурсивная функция для поиска элемента в дереве
    bool search(Node* node, int value) 
    {
        if (node == nullptr) 
        {
            return false;  // если узел пустой, элемент не найден
        }

        if (value == node->value) 
        {
            return true;  // элемент найден
        } 
        else if (value < node->value) 
        {
            return search(node->left, value);  // ищем в левом поддереве
        } 
        else 
        {
            return search(node->right, value);  // ищем в правом поддереве
        }
    }

public:
    // конструктор
    BinarySearchTree() : root(nullptr) {}

    // функция для добавления элемента в дерево
    void add(int value) 
    {
        addNode(root, value);
    }

    // функция для удаления элемента из дерева
    void remove(int value) 
    {
        root = deleteNode(root, value);
    }

    // функция для вывода дерева
    void print() 
    {
        if (root != nullptr) 
        {
            cout << "Корень дерева: " << root->value << endl;  // выводим корень дерева
        }

        // Выводим элементы левой ветви с учетом бинарного поиска
        cout << "Элементы левой ветви: ";
        printLeftBranch(root->left);
        cout << endl;

        // Выводим элементы правой ветви с учетом бинарного поиска
        cout << "Элементы правой ветви: ";
        printRightBranch(root->right);
        cout << endl << endl;

        // Выводим все элементы дерева (in-order)
        cout << "Все элементы дерева (in-order): ";
        printInOrder(root);
        cout << endl << endl;
    }

    // функция для поиска элемента в дереве
    bool search(int value) 
    {
        return search(root, value);
    }

    // деструктор для освобождения памяти
    ~BinarySearchTree() 
    {
        while (root != nullptr) 
        {
            remove(root->value);
        }
    }
};

int main() 
{
    BinarySearchTree tree;

    // добавляем элементы в дерево
    tree.add(50);
    tree.add(30);
    tree.add(70);
    tree.add(60);
    tree.add(20);
    tree.add(80);
    tree.add(40);

    cout << "Дерево после добавления элементов: " << endl;
    tree.print();  // выводим дерево

    // ищем элементы в дереве
    int searchVal = 40;
    cout << "Поиск элемента " << searchVal << ": " << (tree.search(searchVal) ? "Найден" : "Не найден") << endl;

    // удаляем элементы из дерева
    tree.remove(20);
    tree.remove(30);
    tree.remove(50);

    cout << "Дерево после удаления элементов: " << endl;
    tree.print();  // выводим дерево

    // ищем удаленный элемент
    cout << "Поиск удаленного элемента: " << (tree.search(20) ? "Найден" : "Не найден") << endl;

    return 0;
}
