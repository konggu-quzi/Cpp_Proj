#include <iostream>

using namespace std;
class D
{
public:
    void show()
    {
         cout << "D:show" << &this->ID<< endl;
    }
protected:
    int ID = 1000;
private:

};

class B:public D
{
public:
    void show()
    {
         cout << "B:show" << &this->ID<< endl;
    }
protected:
    int ID = 1001;
};
class C:public D
{
public:
    void show()
    {
         cout << "C:show" << &this->ID<< endl;
    }
protected:
    int ID = 1002;
};
class A:public B,public C
{
public:
    void show()
    {
         cout << "A:show" << &this->ID<< endl;
    }
protected:
    int ID = 1003;
};


int main(int argc, char *argv[])
{
    A jack;
    cout << sizeof(jack) << endl;
    jack.show();

    return 0;
}
