#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Normal Recurssive method
// Function can return only one value, so we use static variables to store the power and factorial results 

double taylor(int x, int n)
{   
    static double p=1, f=1;
    double r;
    if(n==0)
        return 1;
    else
    {
        r = taylor(x,n-1);
        p = p*x;
        f = f*n;
        return r + p/f;
    }
}

// Optimized recurssive method
double taylor1(int x, int n)
{
    static double s;
    if(n==0)
        return s;
    s = 1 + x*s/n;
    return taylor1(x, n-1);
}

// Iterative method
double taylor2(int x, int n)
{
    double s=1;
    double num=1, den=1;
    for(int i=1;i<=n;i++)
    {
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}

int main()
{
    cout << taylor2(2,10);
}
