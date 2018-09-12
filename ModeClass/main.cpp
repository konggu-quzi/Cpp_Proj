#include <iostream>

using namespace std;

template <class T = int>
class Array
{
public:
    Array()
    {
        show();
    }
    void show()
    {
        cout << this << endl;
    }
private:
    T *array;
};
int length = 5;

int main(int argc, char *argv[])
{

    Array<char> test[10];

    return 0;
}
