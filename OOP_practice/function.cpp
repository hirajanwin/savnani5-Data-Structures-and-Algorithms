#include <iostream>
#include <cstdio>
using namespace std;


int max_of_four(int a, int b, int c, int d)
{
    if(a>b) 
    {
        if (a>c)
        {
            if (a>d) return a;
        }
        else
        {
            if (c>d) return c;
        }   
    }
    else
    {
        if(b>d)
        { 
            if(b>c) return b;
        }
        else
        {
            if (d>c) return d;
        }
    }
    return 0;
}


int main() 
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);    
    return 0;
}