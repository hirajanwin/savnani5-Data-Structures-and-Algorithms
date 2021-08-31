#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Iterative fibonacci
int fib(int n)
{
    int t0=0, t1=1, s=0;
    if(n<=1)
        return n;
    for(int i=2;i<=n;i++)
    {
        s = t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

// Recurssive fibonacci
int rfib(int n)
{
    if(n<=1)
        return n;
    return rfib(n-2)+rfib(n-1);
}


// Optimized recurssion with memoization
// NOTE: You can only get the fibonacci till the size of the array

int F[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int mfib(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2] = mfib(n-2);
        if(F[n-1]==-1)
            F[n-1] = mfib(n-1);
        return F[n-2]+F[n-1];
    }
}

int main()
{
    cout << mfib(8);
    return 0;
}