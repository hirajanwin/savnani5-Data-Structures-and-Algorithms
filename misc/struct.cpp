# include <iostream>
 using namespace std;

struct Rectangle
{
    int l;
    int b;
};

int main()
{
    struct Rectangle r;
    r.l = 10;
    r.b = 5;
    cout << r.l*r.b;
}
