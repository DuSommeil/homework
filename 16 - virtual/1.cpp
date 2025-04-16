#include <iostream>

using namespace std;

// глобальная константа для определения максимального начального размера стека
const int N=10;

// абстрактный базовый класс для геометрических фигур (fig)
// содержит общие свойства (координаты x0, y0 и размеры a, b)
// и чисто виртуальные функции для полиморфного поведения (копирование,
// вычисление площади, печать)
class fig 
{
    protected:
        float x0, y0; // координаты точек
        float a, b; // размеры фигуры

    public:
    // конструктор по умолчанию 
	fig(float x1=0, float y1=0, float a1=0, float b1=0 ): x0(x1), y0(y1), a(a1), b(b1) {}

    // конструктор копирования
   	fig(fig& f): x0(f.x0), y0(f.y0), a(f.a), b(f.b) {}

    // Виртуальный деструктор (добавлено, не было в коде изначалньо)
    // важен при работе с полиморфизмом и указателями на базовый класс
    virtual ~fig() {}

    // чисто виртуальная функция для создания копии объекта (глубокое копирование)
    // возвращает указатель на новую копию объекта *конкретного* производного типа.
    // необходима для правильного копирования объектов в полиморфных контейнерах.
	virtual fig* copyf() const = 0;

    // виртуальная функция для вычисления площади
	virtual float plosh() const = 0;

    // виртуальная функция для вывода информации об объекте в поток
    // выводит общие данные (координаты) в os
	virtual ostream& prfig(ostream& os) 
    {
		return os << "x0 = " << x0 << ", y0 = " << y0;
    }

    // перегрузка оператора вывода (<<) для полиморфного вывода
    // позволяет использовать `cout << figure_object;` для любого объекта fig
    // или его наследника. вызывает виртуальную функцию `prfig` для конкретного объекта.
	friend ostream &operator<<(ostream &os, fig &f) // использование функции для дружбанов
    {
        return f.prfig(os); //вывод через prfig
    }
};

// класс треугольника
// наследуется от fig
// a и b - катеты
class tre: public fig 
{
    public:
    // конструктор по умолччанию 
        tre(float x1, float y1, float a1, float b1):fig(x1,y1,a1,b1) {} // передаем параметры

    // конструктор копирования
    // вызывает конструктор копирования базового класса.
        tre(tre& f): fig(f) {}

    // реализация функции глубокого копирования (copyf)
    // создает новый объект tre в динамической памяти с теми же данными.
	fig* copyf() const
    {
        return new tre(x0, y0, a, b); // возвращаем указатель на новый объект tre
    }

    // реализация функции вычисления площади (plosh)
    // вычисляет площадь прямоугольного треугольника как (катет1 * катет2) / 2.
	float plosh() const
    {
        return a*b/2; // Формула площади прямоугольного треугольника
    }

    // реализация функции вывода в поток (prfig)
    // сначала вызывает базовую версию `prfig` для вывода координат,
    // затем выводит специфичную для треугольника информацию (катеты).
	ostream& prfig(ostream& os)
    {
        fig::prfig(os); // вызов базовой реализации для вывода x0, y0
        return os << ", kat1 = " << a << ", kat2 = " << b << endl; // вывод специфичных данных для tre (катеты)
    }
};

// класс для прямоугольника (pr)
// наследуется от fig
// a и b интерпретируются как стороны
class pr: public fig 
{
    public:
	pr (float x1, float y1, float a1, float b1) : fig(x1,y1,a1,b1) {} // передача параметров в конструкторе 

    // конструктор копирования
	pr(pr& f): fig(f) {}
    // реализация функции глубокого копирования (copyf)
    // создает новый объект prt в динамической памяти с теми же данными
	fig* copyf() const {
        // возвращаем указатель на новый объект pr
        return new pr(x0, y0, a, b);
    }

    // реализация функции вычисления площади (plosh)
    // вычисляет площадь прямоугольника как сторона1 * сторона2.
	float plosh() const {
        return a*b;
    }

    // реализация функции вывода в поток 
    // сначала вызывает базовую версию prfig для вывода координат
    // затем выводит стороны
	ostream& prfig(ostream& os) {
        fig::prfig(os);
        // вывод сторон
        return os << ", side1 = " << a << ", side2 = " << b << endl;
    }
};


// класс динамического стека для хранения указателей на фигуры 
// реализует структуру данных "стек"
// хранит указатели на базовый класс fig, позволяя полиморфно работать
// с объектами tre и pr, также работает с динамической памятью
class stk 
{
	int len; // текущее количество элементов в стеке
	int mlen; // максимальная вместимость (выделенная память)
	fig** v; // указатель на динамический массив указателей на объекты fig

   public:
    // конструктор, создает стек с начальной вместимостью n, но не более N
    // выделяет память под массив указателей `v`.
    stk(int n): len(0), mlen((n > N || n <= 0) ? N : n)  
    { // добавлена проверка n <= 0
    // выделение памяти для массива указателей
        v = new fig*[mlen];
    }

    // конструктор копирования (глубокое копирование)
    // создает копию другого стека fm
    // копирует не только указатели, но и сами объекты фигур, на которые
    // они указывают, используя виртуальную функцию copyf()
    stk(const stk& fm):len(fm.len), mlen(fm.mlen) 
    {
        v = new fig*[mlen]; // выделение памяти для нового массива указателей
        for (int i=0; i<len; ++i) // копирование каждого элемента с использованием copyf()
        {
            // создаем копию i-го элемента из fm и сохраняем указатель
            v[i] = fm.v[i]->copyf();
        }
    }

    // деструктор
    // удаляет каждый объект фигуры, на который указывают элементы v
    // удаляет сам массив указателей v
    ~stk() 
    {
        for (int i = 0; i < len;) 
        { // удаление каждого объекта фигуры в стеке
            delete v[i++]; // удаляем объект и инкрементируем i
        }
        // освобождение памяти массива указателей
        delete [] v;
    }

    // Перегрузка оператора вывода (<<) для стека
    // Позволяет вывести содержимое стека в поток os
    friend ostream& operator<<(ostream& os, stk &fs); // объявление функции для дружбанов

    // получение текущего размера стека
    int get_size() const { return len; } // добавлено const

    // получение максимальной вместимости стека
    int get_msize() const { return mlen; } // добавлено const

    // увеличение размера (вместимости) стека
    // удваивает вместимость mlen, создает новый, больший массив,
    // копирует указатели из старого массива в новый, удаляет старый массив
    // и обновляет v на новый массив
    int resize() 
    {
        // удваиваем максимальную длину
        mlen *= 2;
        // выделяем память под новый массив указателей
        fig** newv = new (nothrow) fig*[mlen]; // использовать nothrow для проверки
        if (newv) 
        { // проверяем успешность выделения памяти
            // копируем указатели из старого массива в новый
            for (int i=0; i<len; ++i) 
            {
                newv[i]=v[i];
            }
            // освобождаем память старого массива
            delete[] v;
            // указатель v теперь указывает на новый массив
            v = newv;
            return 1; // ура ура
        }
        // ошибка выделения памяти
        cerr << "Error memory allocation!" << endl;
        mlen /= 2; // возвращаем старое значение mlen в случае ошибки
        return 0; // плаки плаки
    }

    // извлечение элемента из вершины стека 
    // возвращает указатель на элемент из начала массива (v[0])
    // удаляет его из стека, сдвигая остальные элементы влево
    // возвращает nullptr (0), если стек пуст
    // од становится владельцем возвращенного указателя
    // и должен сам позаботиться о его удалении (`delete`).
    fig* pop() 
    {
        // проверка на пустоту стека
        if (!len) return nullptr; // возвращаем nullptr, если стек пуст
        // сохраняем указатель на первый элемент (вершину)
        fig* f = v[0];
        // сдвигаем все последующие элементы на одну позицию влево
        for (int i = 1; i < len; ++i) 
        {
            v[i-1] = v[i];
        }
        // уменьшаем текущую длину стека
        len--;
        // возвращаем указатель на извлеченный элемент
        return f;
    }

    // добавление элемента на "вершину" стека
    // добавляет *копию* фигуры f в начало массива (v[0])
    // сначала сдвигает все существующие элементы вправо
    // если стек полон, вызывает resize() для увеличения вместимости
    // использует f.copyf() для создания глубокой копии добавляемой фигуры
    int push(const fig& f) 
    {
        // если стек полон, пытаемся увеличить его размер
        if (len == mlen) 
        {
            if (!resize()) 
            { // если resize не удался
                 return 0; // плаки плаки
            }
        }
        // сдвигаем все существующие элементы на одну позицию вправо
        // чтобы освободить место для нового элемента в v[0]
        for (int i = len; i > 0; --i) 
        {
            v[i] = v[i-1];
        }
        // увеличиваем текущую длину стека
        len++;
        // создаем копию объекта f с помощью copyf() и помещаем указатель в v[0]
        v[0] = f.copyf();
        // проверка, что copyf не вернул nullptr 
        if (!v[0]) {
            len--; // откатываем увеличение длины
            cerr << "Error creating copy of figure!" << endl;
            return 0; // плаки плаки
        }
        return 1; // ура ура
    }
};

// реализация перегруженного оператора вывода (<<) для стека
// выводит заголовок и затем каждый элемент стека в отдельной строке
// используя перегруженный оператор << для класса fig (который вызывает prfig).
ostream& operator<<(ostream& os, stk &f) 
{
   os << endl << "***** Stack of geometric objects (Size: " << f.len << ", Capacity: " << f.mlen << ") *****" << endl;
   // проход по всем элементам стека
   for (int i=0; i < f.len; ++i) 
   {
       // вывод индекса и информации о фигуре (используется operator<< для fig)
       // добавляем проверку на nullptr на всякий случай
       if (f.v[i]) 
       {
            os << "i = " << i << ", figure=" << *f.v[i] << endl; // добавлен endl здесь
       } 
       else 
       {
           os << "i = " << i << ", figure=<NULL>" << endl;
       }
   }
   os << "***** End of Stack *****" << endl;
   return os;
}

int main() 
{
    cout << "--- Создание фигур ---" << endl;
    // создаем объекты разных фигур 
    tre triangle1(1, 1, 3, 4); // прямоугольный треугольник с катетами 3 и 4
    pr rectangle1(5, 5, 6, 2); // прямоугольник со сторонами 6 и 2
    tre triangle2(0, 0, 5, 12); // еще один треугольник
    pr rectangle2(-2, -3, 10, 10); // квадрат (частный случай прямоугольника)

    cout << "Фигура 1: " << triangle1 << " Площадь: " << triangle1.plosh() << endl;
    cout << "Фигура 2: " << rectangle1 << " Площадь: " << rectangle1.plosh() << endl;
    cout << "Фигура 3: " << triangle2 << " Площадь: " << triangle2.plosh() << endl;
    cout << "Фигура 4: " << rectangle2 << " Площадь: " << rectangle2.plosh() << endl;

    cout << "\n--- Создание и заполнение стека ---" << endl;
    // создаем стек с начальной вместимостью 2
    stk myStack(2);
    cout << "Начальный стек:" << myStack;

    // добавляем фигуры в стек (push создает копии!)
    cout << "Добавляем triangle1..." << endl;
    myStack.push(triangle1);
    cout << "Стек после добавления triangle1:" << myStack;

    cout << "Добавляем rectangle1..." << endl;
    myStack.push(rectangle1);
    cout << "Стек после добавления rectangle1:" << myStack;

    // стек полон (size=2, capacity=2), следующее добавление вызовет resize()
    cout << "Добавляем triangle2 (вызовет resize)..." << endl;
    myStack.push(triangle2);
    cout << "Стек после добавления triangle2:" << myStack; // вместимость должна стать 4

    cout << "Добавляем rectangle2..." << endl;
    myStack.push(rectangle2);
    cout << "Стек после добавления rectangle2:" << myStack;

    cout << "\n--- Демонстрация Pop ---" << endl;
    // извлекаем элемент из стека
    fig* poppedFig = myStack.pop();
    if (poppedFig) 
    { // проверяем, что элемент успешно извлечен
        cout << "Извлечен элемент (Pop): " << *poppedFig << endl;
        cout << "Площадь извлеченного элемента: " << poppedFig->plosh() << endl;
        // удаляем объект, так как pop передал нам владение
        delete poppedFig;
        poppedFig = nullptr; // обнуляем указатель после delete
    } else {
        cout << "Стек пуст, извлечь нечего." << endl;
    }
    cout << "Стек после Pop:" << myStack;

    // извлекаем еще один элемент
    poppedFig = myStack.pop();
     if (poppedFig) {
        cout << "Извлечен элемент (Pop): " << *poppedFig << endl;
        cout << "Площадь извлеченного элемента: " << poppedFig->plosh() << endl;
        delete poppedFig;
        poppedFig = nullptr;
    }
    cout << "Стек после второго Pop:" << myStack;


    cout << "\n--- Демонстрация конструктора копирования ---" << endl;
    // создаем копию стека
    stk copiedStack = myStack; // вызывается конструктор копирования stk(const stk&)
    cout << "Оригинальный стек:" << myStack;
    cout << "Скопированный стек:" << copiedStack;

    // проверим, что это глубокая копия, добавив элемент в копию
    cout << "Добавляем triangle1 в скопированный стек..." << endl;
    copiedStack.push(triangle1);
    cout << "Оригинальный стек (не изменился):" << myStack;
    cout << "Скопированный стек (изменился):" << copiedStack;

    // проверим, что удаление оригинала не влияет на копию (и наоборот)
    // деструкторы будут вызваны автоматически при выходе из main

    cout << "\n--- Конец ---" << endl;

    // объекты стеков myStack и copiedStack будут автоматически уничтожены здесь
    // их деструкторы (~stk) вызовут delete для всех оставшихся в них фигур
    return 0;
}
