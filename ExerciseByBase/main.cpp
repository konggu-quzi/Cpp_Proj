#include <iostream>

using namespace std;

#define random(x,y) (rand()%(y-x)+x);


class StuInfo
{
public:
    StuInfo(string _name,int _CardID)
    {
        name = _name;
        CardID = _CardID;
        balance = random(50,200);
    }
    void show_balance()
    {
        cout << "name:" << name << " balance:" << balance << endl;
    }
protected:
    string name;
    int CardID;
    int balance;
};

class Graduate_StuInfo:public StuInfo
{
public:
    Graduate_StuInfo(string _name,int _CardID,string _tutor,int _wage):StuInfo(_name,_CardID)
    {
        tutor = _tutor;
        wage = _wage;
    }
    void show_balance()
    {
        StuInfo::show_balance();
        cout << "tutor name:" << tutor << " wage:" << wage << endl;
    }
private:
    string tutor;
    int wage;
};


int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    StuInfo jack("jack",311);
    jack.show_balance();
    Graduate_StuInfo tony("tony",312,"Tom",1300);
    tony.show_balance();


    return 0;
}
