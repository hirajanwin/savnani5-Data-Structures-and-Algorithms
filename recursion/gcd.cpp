#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Using recursion
int rgcd(int m, int n)
{
    if(n!=0)
        return rgcd(n, m%n);
    else
        return m;    
}


// Iterative gcd
int gcd(int m, int n)
{
    int max=0, iter;
    if(m<n)
        iter = m;
    else
        iter = n;
    for(int i=1; i<=(iter/2)+1; i++)
    {
        if(m%i==0 && n%i==0)
            max = i;
    }
    return max;
}


int main()
{
    cout << rgcd(10,15);
}