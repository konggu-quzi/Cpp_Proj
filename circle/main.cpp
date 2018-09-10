#include <iostream>

using namespace std;

class CircleInfo
{
public:
    CircleInfo(int _radius,int _height);
protected:
    int radius;
    int height;
};

class Cal_Circle_agrc:public CircleInfo
{
public:
    Cal_Circle_agrc(int _radius,int _height):CircleInfo( _radius,_height){}
    void show_Circle_agrc();
};

CircleInfo::CircleInfo(int _radius,int _height)
{
    radius = _radius;
    height = _height;
}
void Cal_Circle_agrc::show_Circle_agrc()
{
   cout << "Circle_radius:" << CircleInfo::radius << endl;
   cout << "Circle_area:" << 3.14159*(CircleInfo::radius)*(CircleInfo::radius) << endl;
   cout << "Circle_perimeter:" << 2*3.14159*CircleInfo::radius << endl;
   cout << "Circle_volume:" << 3.14159*(CircleInfo::radius)*(CircleInfo::radius)*(CircleInfo::height) << endl;
}


int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
//    CircleInfo test;
    Cal_Circle_agrc test(5,5);
    test.show_Circle_agrc();
    return 0;
}
