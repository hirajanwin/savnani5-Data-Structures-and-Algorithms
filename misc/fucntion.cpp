#include <iostream>
#include <stdio.h>

using namespace std;

int add(int a, int b)
{
    return a+b;
}

int main()
{
    int x=10, y=5, z;
    z = add(x,y);
    cout << z <<endl;

}