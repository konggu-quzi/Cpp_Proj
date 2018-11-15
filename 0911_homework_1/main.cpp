#include <iostream>
#include <cstdio>

using namespace std;
class A{
    public:
        A(){p();}
        virtual void p(){cout<<"A"<<endl;}
        virtual ~A(){cout<<"~A"<<endl;}
};
class B:public A{
    public:
        B(){p();}
        void p(){cout<<"B"<<endl;}
        ~B(){cout<<12<<endl;}
};
int main(int, char**){
    int aa = 12,n=5;
    aa%=(n%2);+6+6+6+6+6+66+6+6+6+6+6+6+690
    cout<<aa<<endl;
        A* a=new B();
        delete a;
}
