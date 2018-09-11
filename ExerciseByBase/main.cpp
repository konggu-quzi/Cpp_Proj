//1.面向对象多态的实现
//	1.c++的多态性就是通过晚绑定技术来实现的。
//	2.在基类的函数前加上virtual关键字，在派生类中重写该函数，
//运行时将会根据对象的实际类型来调用相应的函数，如果对象类型是派生类，
//就调用派生类的函数，如果对象类型是基类，就调用基类的函数。


//*编译器在编译的时候，发现Father类中有虚函数，此时编译器会为每个包含虚函数的类创建一个虚表(即 vtable)，该表是一个一维数组，在这个数组中存放每个虚函数的地址，



//那么如何定位虚表呢？编译器另外还为每个对象提供了一个虚表指针(即vptr)，这个指针指向了对象所属类的虚表，在程序运行时，根据对象的类型去初始化vptr，从而让vptr正确的指向了所属类的虚表，从而在调用虚函数的时候，能够找到正确的函数，对于第二段代码程序，由于pFather实际指向的对象类型是Son，因此vptr指向的Son类的vtable，当调用pFather->Son()时，根据虚表中的函数地址找到的就是Son类的Say()函数.

//　　正是由于每个对象调用的虚函数都是通过虚表指针来索引的，也就决定了虚表指针的正确初始化是非常重要的，换句话说，在虚表指针没有正确初始化之前，我们不能够去调用虚函数，那么虚表指针是在什么时候，或者什么地方初始化呢？

//　　答案是在构造函*/数中进行虚表的创建和虚表指针的初始化，在构造子类对象时，要先调用父类的构造函数，此时编译器只“看到了”父类，并不知道后面是否还有继承者，它初始化父类对象的虚表指针，该虚表指针指向父类的虚表，当执行子类的构造函数时，子类对象的虚表指针被初始化，指向自身的虚表。
#include <iostream>
#include <stdlib.h>
using namespace std;

class CA
{
public:
    void f()
    {
        cout << "CA f()" << endl;
    }
    virtual void ff()
    {
        cout << "CA ff()" << endl;
        f();
    }
};

class CB : public CA
{
public :
    virtual void f()
    {
        cout << "CB f()" << endl;
    }
    void ff()
    {
        cout << "CB ff()" << endl;
        f();
        CA::ff();
    }
};
class CC : public CB
{
public:
    virtual void f()
    {
        cout << "C f()" << endl;
    }
};

int main()
{
    CB b;
    CA *ap = &b;
    CC c;
    CB &br = c;
    CB *bp = &c;

    ap->f();
    cout << endl;

    b.f();
    cout << endl;

    br.f();
    cout << endl;

    bp->f();
    cout << endl;

    ap->ff();
    cout << endl;

    bp->ff();
    cout << endl;

    return 0;
}
