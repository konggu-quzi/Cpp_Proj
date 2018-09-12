#include <iostream>

using namespace std;




class Array
{
public:
    Array(int n):length(n)
    {
        this->arr = new int[this->length];
    }
    ~Array()
    {
        delete []arr;
    }

    //重载中括号[]
    int& operator[](int i)
    {
        return this->arr[i] ;
    }

    //重载小括号（）
    void operator ()(int start, int end, int value)
    {
        for(int i=start; i<end ; i++)
        {
            this->arr[i] = value;
        }
    }

protected:
    int *arr;
    int length;
};




int main(int argc, char *argv[])
{

    Array myArray(100);
    myArray[0] = 100;

    cout<<myArray[0]<<endl;


    myArray(0,5,123);
    cout<<myArray[0]<<myArray[1]<<myArray[2]<<myArray[3]<<myArray[4]<<myArray[5]<<endl;

    return 0;
}
