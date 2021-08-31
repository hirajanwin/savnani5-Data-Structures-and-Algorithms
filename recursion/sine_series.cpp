#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double sine(int x, int n)
{
    static double p=x, f=1, c=1;
    double r;
 
    if(n==1)
        return x;
    else
    {
        r = sine(x,n-1);
        p = p*x*x;
        f = f*(c+1)*(c+2);
        c +=2;
        if(n%2==0)
            return r - p/f;
        else
            return r + p/f;
    }   
}

int main()
{
    cout << sine(2,10);
}
