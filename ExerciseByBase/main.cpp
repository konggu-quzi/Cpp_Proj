#include <iostream>

using namespace std;

class StuInfo
{
public:
    StuInfo();
protected:
    string name;
    int CardID;
};

class Graduate_StuInfo:public StuInfo
{
public:
    Graduate_StuInfo():StuInfo()
    {

    }
private:
    string tutor;
    int wage;
};


int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
