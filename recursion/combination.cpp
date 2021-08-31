#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// A function with factorials and formula(n!/r!(n-r)!) can also be written

int nCr(int n, int r)
{   
    if(n<r)
        return -1;
    if(r==0 || n==r)
        return 1;
    else
        return nCr(n-1, r-1) + nCr(n-1, r);
}

int main()
{
    cout << nCr(5,3);
}
