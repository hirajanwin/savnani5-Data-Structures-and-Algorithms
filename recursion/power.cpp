#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Power allowing negatives too
// Headsup: Typecasting problem(define m and n as doubles)

double npow(double m, double n)
{
    if(n==0)
        return 1;
    else if(n<0)
        return (1/m)*npow(m,n+1);
    else
        return m*npow(m,n-1);
}

int pow(int m, int n)
{
    if(n==0)
        return 1;
    return m*pow(m,n-1);

}

int pow1(int m, int n)
{
    if(n==0)
        return 1;
    if((n%2)==0)
        return pow(m*m, n/2);
    else
        return m*pow(m*m, (n-1)/2);

}

int main()
{
    cout << npow(5,-4);
}