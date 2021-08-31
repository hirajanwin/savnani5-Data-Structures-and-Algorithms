#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Diagonal
{
    private:
        int n;
        int *A;

    public:
        Diagonal(int num)
        {
            n = num;
            A = new int[n];
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~Diagonal();
};

void Diagonal::set(int i, int j, int x)
{
    if(i==j)
        A[i-1]=x;
}

int Diagonal::get(int i, int j)
{
    if(i==j)
        return A[i-1];
    return 0;
}

void Diagonal::display()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
                cout << A[i] << " ";
            else
                cout << "0 ";
        } 
        cout << endl;
    }
}

Diagonal::~Diagonal()
{
    delete []A;
}

int main()
{
    Diagonal d(4);
    d.set(1,1,5);
    d.set(2,2,2);
    d.set(3,3,4);
    d.set(4,4,3);
    d.display();
    return 0;
}