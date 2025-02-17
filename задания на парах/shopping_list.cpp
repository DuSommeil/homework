#include <iostream>
#include <string.h>
using namespace std;



class Grocery
    {
        string Name;
        string Shop_name;
        int Price;
        int Quantity;
        string Unit;

    public:
        Grocery(string n, string s, int p, int q, string u):Name(n), Shop_name(s), Price(p), Quantity(q), Unit(u){}
        Grocery():Name(""), Shop_name(""), Price(0), Quantity(0), Unit(""){}
        Grocery(Grocery &gr):Name(gr.Name), Shop_name(gr.Shop_name), Price(gr.Price), Quantity(gr.Quantity), Unit(gr.Unit){}

        void Print() const
        {
            cout << "Название товара: " << Name << endl;
            cout << "Название магазина: " << Shop_name << endl;
            cout << "Цена: " << Price << endl;
            cout << "Количество: " << Quantity << endl;
            cout << "Единица измерения: " << Unit << endl;
        }
    };

    class Grocery_list
    {
        Grocery* list;
        int size;
    public:
        Grocery_list(): list(nullptr), size(0) {}

        ~Grocery_list()
        {
            delete[] list;
            cout << "Память освобождена" << endl;
        }

        void Change_grocery(int ind);
        void Append() const 
        {
            string Name, Shop_name, Unit;
            int Price, Quantity;

            cout << "Введите название товара" << endl;
            cin >> Name;
            cout << "Введите название магазина" << endl;
            cin >> Shop_name;
            cout << "Введите цену" << endl;
            cin >> Price;
            cout << "Введите количество" << endl;
            cin >> Quantity;
            cout << "Введите единицу измерения" << endl;
            cin >> Unit;

            Grocery* new_list = new Grocery[size + 1];

            for (int i = 0; i < size; i++)
            {
                new_list[i] = list[i];
            }

                // Добавляем новый товар
        new_list[size] = Grocery(Name, Shop_name, Price, Quantity, Unit);

        delete[] list;
        list = new_list;
        ++size;

        cout << "Товар успешно добавлен!" << endl;
            cout << "Товар успешно добавлен!" << endl;
        }
        void Sort(bool fl);
        void Print();
        

        
        ~Grocery_list()
        {
            cout << "Деструктор вызван" << endl;
        }
    };

int main()
{
    return 0;
}

#include <iostream>
using namespace std;

class item
{
        string name;
        string shop_name;
        int price;
        int quantity;
        string unit;
    public:
        item():name(""), shop_name(""),price(0),quantity(0),unit(""){}
        item(string _name, string _shop_name, int _price, int _quantity, string _unit):
            name(_name), shop_name(_shop_name), price(_price), quantity(_quantity), unit(_unit){}
        void set_values(string _name, string _shop_name, int _price, int _quantity, string _unit)
        {

        }
        void console_vals()
        {

        }
        void print()
        {

        }
        string pull_shop_name()
        {

        }
        string pull_item_name()
        {

        }
};

class item_list
{
    item* list;
    const int max_size;
    int size;

    public:
    item_list():max_size(128), size(0)
    {

    };
    void change_item(int ind)
    {
        if (ind < size)
        {
            list[ind].console_vals();
        }
        else
        {
            cout << "Товара не существует" << endl;
        }
    }
    void append()
    {

    };
    void sort_byShop()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > i; j++)
            {
                if(list[j].pull_shop_name()>list[j-1].pull_shop_name())
                {
                    item buf = list[j];
                    list[j] = list[j - 1];
                    list[j - 1] = buf;
                }
            }
        }
    }
    void sort_byName()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > i; j++)
            {
                if(list[j].pull_item_name()>list[j-1].pull_item_name())
                {
                    item buf = list[j];
                    list[j] = list[j - 1];
                    list[j - 1] = buf;
                }
            }
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            list[i].print();
            cout << endl;
        }
    }
};

int main()
{
    item_list items;

    for (int i = 0; i < 5; i++)
    {
        items.append();
    }

    items.print();

    items.change_item(2);
    items.print();

    items.sort_byName();
    items.print();

    items.sort_byShop();
}