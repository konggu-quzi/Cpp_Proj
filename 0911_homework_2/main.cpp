#include <iostream>

using namespace std;

class shape
{
public:
    shape(string _name):name(_name){}
    virtual void Cal_area() = 0;
    void show()
    {
        cout << name << " area:" << area << endl;
    }
protected:
    double area;
private:
    string name;

};

class circle:public shape
{
public:
    circle(double _radius):radius(_radius),shape("circle"){}
    void Cal_area()
    {
        shape::area = 3.14159 * radius * radius;
    }
protected:

private:
    double radius;
};

class rectangle:public shape
{
public:
    rectangle(double _width,double _height):width(_width),height(_height),shape("rectangle"){}
    void Cal_area()
    {
        shape::area = width * height;
    }
protected:

private:
    double width;
    double height;
};

class trapezoid:public shape
{
public:
    trapezoid(double _top_width,double _down_width,double _height):top_width(_top_width),down_width(_down_width),height(_height),shape("trapezoid"){}
    void Cal_area()
    {
        shape::area = (top_width + down_width) * height/2;
    }
protected:

private:
    double top_width;
    double down_width;
    double height;
};

int main(int argc, char *argv[])
{
    cout << "Plz input short name of figure that u want to cal its area" << endl;
    string type;
    cin >> type ;

    if(type == "yx")
    {
        cout << "Plz input radius" << endl;
        double radius;
        cin >> radius;

        circle test(radius);
        shape *sh = &test;

        sh->Cal_area();
        sh->show();
    }
    else if(type == "cfx")
    {
        cout << "Plz input width and height" << endl;
        double width,height;
        cin >> width >> height ;

        rectangle test(width,height);
        shape *sh = &test;

        sh->Cal_area();
        sh->show();

    }
    else if(type == "tx")
    {
        cout << "Plz input top_width and down_width and height" << endl;
        double top_width,down_width,height;
        cin >> top_width >> down_width >> height;

        trapezoid test(top_width,down_width,height);
        shape *sh = &test;

        sh->Cal_area();
        sh->show();
    }

    return 0;
}
