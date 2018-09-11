#include <iostream>

using namespace std;

class sell_info
{
public:
    sell_info(string name):ProductName(name),data(5)
    {}
    void Rose()
    {
        nums -= 10;
    }
    void Jack()
    {
        nums -= 15;
    }
    void Jim()
    {
        nums -= 13;
    }
    void show_nums()
    {
        cout << ProductName << " nums:" << nums << endl;
    }
    static int nums;
protected:
    string ProductName;
    int data;
private:

};
int sell_info::nums = 100;

int main(int argc, char *argv[])
{
    sell_info milk("milk");
    milk.show_nums();

    return 0;
}
