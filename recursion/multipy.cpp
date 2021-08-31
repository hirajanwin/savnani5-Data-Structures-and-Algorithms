#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// if a*b, then a+a+a... b times
int mul(int a, int b)
{
    if(b==1)
        return a;
    return a + mul(a,b-1);
}

int main()
{
    cout << mul(20,8);
}