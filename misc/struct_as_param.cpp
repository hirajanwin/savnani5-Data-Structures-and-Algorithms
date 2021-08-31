#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Pass by value
// struct Rectangle
// {
//     int l;
//     int b;
// };

// void fun(struct Rectangle r)
// {
//     r.l = 20;
//     cout << r.l << " " << r.b << endl;
// }

// int main()
// {
//     Rectangle r={10,5};
//     fun(r);
//     cout << r.l << " " << r.b << endl;
//     return 0;
// }


// Pass by address
// struct Rectangle
// {
//     int l;
//     int b;
// };

// void fun(struct Rectangle *p)
// {
//     p->l = 20;
//     cout << p->l << " " << p->b << endl;
// }

// int main()
// {
//     Rectangle r={10,5};
//     fun(&r);
//     cout << r.l << " " << r.b << endl;
//     return 0;
// }


// Creating an object in the function
struct Rectangle
{
    int l;
    int b;
};

Rectangle* fun()
{
    Rectangle *p;
    p = new Rectangle; 
    p->l = 20;
    p->b = 10;
    return p;
}

int main()
{
    Rectangle *p = fun(); 
    cout << p->l << " " << p->b << endl;
    return 0;
}