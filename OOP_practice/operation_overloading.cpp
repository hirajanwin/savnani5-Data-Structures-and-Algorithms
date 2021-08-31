#include <iostream>
#include <string>
using namespace std;

class Rational 
{
     public:
        int p;
        int q;
   
        Rational()
        {
           p = 1;
           q = 1; 
        }
        Rational(int pt, int qt)
        {
            this->p = pt;
            this->q = qt;
        }

        friend Rational operator+(Rational r1, Rational r2);
        friend ostream & operator<<(ostream &o, Rational &r);
};

Rational operator+(Rational r1, Rational r2)
{
    Rational rt;
    rt.p = r1.p*r2.q + r2.p*r1.q;
    rt.q = r1.q*r2.q;
    return rt;  
}

ostream & operator<<(ostream &out, Rational &r)
{
    out<<"Sum of given rational numbers is  "<<r.p<<"/"<<r.q;
    return out;
}

int main()
{
    Rational r1(10,5), r2(3,7), r3;
    r3 = r1 + r2;
    cout<< r3;
}