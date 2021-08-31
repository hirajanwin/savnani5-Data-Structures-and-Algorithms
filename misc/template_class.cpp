#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <class T>
class Arithmetic
{
    private:
        T a;
        T b;
    public:
        Arithmetic(T a, T b);
        T add();
        T subtract();
};

template <class T>
Arithmetic<T> :: Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T> :: add()
{
    T c;
    c = a+b;
    return c;
}

template <class T>
T Arithmetic<T> :: subtract()
{
    T c;
    c = a-b;
    return c;
}

int main()
{
    Arithmetic<int> ar1(10,5);
    cout << ar1.add() << endl;
    Arithmetic<float> ar2(1.5,1.2);
    cout << ar2.add();
}
