#include <iostream>

using namespace std;

class base 
{
    public: virtual void vfunc()
    {
        cout <<"vfunc() iz base.\n"; 
    }
};
class derived1: public base 
{
    public:
    void vfunc()
    {
        cout << "vfunc() iz derived1\n";
    }
};

class derived2: public base 
{
    public:
    void vfunc()
    {
        cout << "vfunc() iz derived2\n";
    }
};

int main()
{
    base *p, b; derived1 d1; derived2 d2;

    p = &b;
    p->vfunc();

    p = &d1;
    p->vfunc();

    p = &d2;
    p->vfunc();

    return 0;
}