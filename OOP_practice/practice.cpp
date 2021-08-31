#include <iostream>
#include <string>
using namespace std;

class Rectangle
{
    private:
        int length;
        int breadth;

    public:
        Rectangle(int l=0, int b=0)
        {
            setlength(l);
            setbreadth(b); 
        }
        
        void setlength(int l)
        {
            length = l;
        }

        void setbreadth(int b)
        {
            breadth = b;
        }

        int area()
        {
            return length*breadth;
        }
        
        int perimeter();
};

int Rectangle :: perimeter()
    {
        return 2*(length + breadth);
    }

int main()
{
    Rectangle r1(10,10);
    Rectangle r2(10,5);
    cout << "R1 area" << r1.area() << "R2 area" << r2.area() << endl;
    cout << "Perimeter" << r1.perimeter();
    return 0;
}                       
