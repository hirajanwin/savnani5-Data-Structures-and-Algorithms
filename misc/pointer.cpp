#include <iostream>
#include <stdio.h>

using namespace std;

class Rectangle
{
    public:
        int l;
        int b;
};


int main()
{
    // int *p;
    // int a = 10;
    // p = &a;


    // p = new int[10];
    // p[0] = 9;
    // p[1] = 10;
    // for (int i=0 ; i< 10; i++)
    // {
    //     cout << p[i] << endl;
    // }

    Rectangle *p;
    p = new Rectangle;
    p->l = 15;
    p->b = 10;
    cout << p->l << p->b;

       
    return 0;
}