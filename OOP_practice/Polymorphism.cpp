#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Shape
{   
    public:
        virtual float area()=0;
        virtual float perimeter()=0;
};


class Rectangle : public Shape
{
    private:
        float len;
        float bre;
    
    public:
        Rectangle(int l=1, int b=1)
        {
            len = l;
            bre = b; 
        }
        float area()
        {
            return len*bre;
        }
        float perimeter()
        {
            return 2*(len+bre);
        }
};

class Circle : public Shape
{
    private:
        float radius;
  
    public:
        Circle(float r =1)
        {
            radius = r;
        }
        float area()
        {
            return 2*3.14*pow(radius,2);
        }
        float perimeter()
        {
            return 2*3.14*radius;
        }
   
};

 int main()
{
    Rectangle r(10,200);
    Circle c(100);
    Shape *s= &r;
    cout << "area " << r.area() << endl;
    cout << "p " << r.perimeter() << endl;

    s = &c;
    cout << "Area " << c.area() << endl;
    cout << "Perimeter " << c.perimeter();   
}