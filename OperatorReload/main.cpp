
#include <iostream>

using namespace std;

class Complex
{
public:
    Complex(){}
    Complex(double r,double i):real(r),imag(i){}
    void show()
    {
        cout << real << "," << imag << endl;
    }

    Complex operator-(Complex &tmp)
    {
        Complex _return;//(0,0);
        _return.real = this->imag - tmp.real;
        _return.imag = this->imag - tmp.imag;
        return _return;
    }
private:
    double real;
    double imag;

};

int main(int argc, char *argv[])
{

    Complex test1(5,5);
    test1.show();
    Complex test2(2,3);
    test2.show();

    Complex test3 = test1 - test2;
    test3.show();


    return 0;
}
