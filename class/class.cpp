#include <iostream>

using namespace std;

class Rectangle
{
    int length;
    int breadth;

public:
    // INSTEAD OF INITIALIZE FUNCTION WE USE A constructor FOR INITIALIZATION
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    void changeLength(int l)
    {
        length = l;
    }
};

int main()
{
    Rectangle r(10, 5);

    cout << "Area of the Rectangle is " << r.area() << endl;

    r.changeLength(20);

    cout << "Area of the Rectangle is " << r.area() << endl;

    return 0;
}
