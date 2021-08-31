// Implemented for the lower triang matrix-- upper triang etc

#include <iostream>
#include <stdio.h>
using namespace std;


class LowerTri
{
    private:
        int n;
        int *A;

    public:
        LowerTri(int n);
        void create();
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~LowerTri();
};

LowerTri::LowerTri(int n)
{
    this->n=n;
    A = new int[n*(n+1)/2];
}

void LowerTri::create()
{
    int x;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> x;
            if(i>=j)
                A[(i*(i-1)/2)+j-1] = x;
        }
    }
}

void LowerTri::set(int i, int j, int x)
{
    if(i>=j)
        A[(i*(i-1)/2)+j-1] = x;
}

int LowerTri::get(int i, int j)
{
    if(i>=j)
        return A[(i*(i-1)/2)+j-1];
    return 0;
}

void LowerTri::display()
{
    int x;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i>=j)
                cout << A[(i*(i-1)/2)+j-1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

LowerTri::~LowerTri()
{
    delete []A;
}

int main()
{   
    LowerTri L(4);
    L.create();
    L.display();
}