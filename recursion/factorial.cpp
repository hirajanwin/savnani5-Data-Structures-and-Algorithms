#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// For large value of n, what is the formula ? For small value of n, what is the answer ?
double fact(double n)
{
    if (n==0)
        return 1;
    else
        return fact(n-1)*n;
}   

int main()
{
    double f;
    f = fact(30);
    cout << f;
}

