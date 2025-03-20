#include <iostream>

using namespace std;

const int SIZE = 10;

template <class AType>
class atype {
private:
    AType a[SIZE];

public:
    atype() {
        for (int i = 0; i < SIZE; i++) {
            a[i] = i;
        }
    }

    AType &operator[](int i) {
        if (i < 0 || i >= SIZE) {
            cerr << "Ошибка: индекс " << i << " выходит за границы массива!\n";
            exit(1);
        }
        return a[i];
    }

    // Геттер для доступа к элементу по индексу (без выхода за границы)
    AType get(int i) const {
        if (i < 0 || i >= SIZE) {
            cerr << "Ошибка: индекс " << i << " выходит за границы массива!\n";
            exit(1);
        }
        return a[i];
    }

    // Перегрузка оператора вывода
    template <class T>
    friend ostream &operator<<(ostream &out, const atype<T> &arr);
};

// Реализация перегруженного оператора вывода
template <class T>
ostream &operator<<(ostream &out, const atype<T> &arr) {
    out << "[ ";
    for (int i = 0; i < SIZE; i++) {
        out << arr.get(i) << " ";
    }
    out << "]";
    return out;
}

int main() {
    atype<int> myArray;
    
    cout << "Содержимое массива: " << myArray << endl;

    // Проверка работы оператора []
    cout << "Элемент с индексом 3: " << myArray[3] << endl;
    
    return 0;
}
