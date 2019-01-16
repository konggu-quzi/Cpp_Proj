#include <iostream>
#include <cstdio>
using namespace std;
class CSingleton
{
private:
    CSingleton() {
    }
    ~CSingleton() {
        cout << "~()" << endl;
        if (m_pInstance == NULL) {
            return;
        }
        delete m_pInstance;
        m_pInstance = NULL;

    }
    static CSingleton *m_pInstance;
public:
    static CSingleton * GetInstance() {
        if(m_pInstance == NULL)
            m_pInstance = new CSingleton();
        return m_pInstance;
    }
};
CSingleton* CSingleton::m_pInstance = NULL;//类的静态成员变量需要在类外边初始化
struct person1{
    char aa;
    char aa2;
    int id;
}__attribute__((packed));//


union da{
    int a;
    char b;
    double c;
}data;

void fun1(void)
{
    cout << "fun1" << endl;
    return;
}
void fun2(void (*p)(void))
{
   (*p)();
   cout << "fun2" << endl;
   return;
}

typedef void (*f1)(void(*f2)(void));

class B
{
public:
    virtual void Fun()
    {
        cout << "B fun" << endl;
    }
};
class D: public B
{
public:
   void Fun()
   {
       cout << "D fun" << endl;
   }
};

int main() {

    D dd;
    B* pb = &dd;
    D* pd = &dd;
    pb->Fun();
    pd->Fun();

    int bb=10;
//    int &constaa;
    f1 a = &fun2;

    (*a)(fun1);

    CSingleton* single1 = CSingleton::GetInstance();
    CSingleton* single2 = CSingleton::GetInstance();

    char str2[] = "\n3a";
    if (single1 == single2) {
        cout<<"Same"<<endl;
    }

    data.a = 5;
    char s[]="";
    cout << sizeof( s) << endl;


    cout << sizeof( str2) << endl;
    return 0;
}
