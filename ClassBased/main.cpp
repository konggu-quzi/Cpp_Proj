#include <iostream>

using namespace std;
class D
{
public:
    D()
    {
        show();
    }
    void show()
    {
         cout << "D:show " << &this->ID<< endl;
    }
protected:
    int ID = 1000;
private:

};

class B:virtual public D
{
public:
    B()
    {
        show();
    }
    void show()
    {
         cout << "B:show " << &this->ID<< endl;
    }
protected:
    int ID = 1001;
};
class C:virtual public D
{
public:
    C()
    {
        show();
    }
    void show()
    {
         cout << "C:show " << &this->ID<< endl;
    }
protected:
    int ID = 1002;
};
class A:public B,public C
{
public:
    A()
    {
        show();
    }
    void show()
    {
         cout << "A:show " << B::ID<< endl;
    }
protected:
    int ID = 1003;
};


int main(int argc, char *argv[])
{
    A jack;
    cout << sizeof(jack) << endl;
//    jack.show();
//    jack.show();
//    jack.show();

    return 0;
}
