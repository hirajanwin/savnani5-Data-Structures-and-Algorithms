#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Recurrence relation: For large value of n, what is the formula ? For small value of n, what is the answer ?

int fun(int n)
{
    if (n==0)
        return 0;
    else
        return fun(n-1) + n;
}

int main()
{
    int sum;
    sum = fun(5);
    cout << sum;
    return 0;
}


// Sum of n numbers using loops, time comlexity O(n)

// int fun(int n)
// {
//     int i, sum=0;
//     for(int i=0; i<n; i++)
//         sum = sum+i;
//     return sum;
// }


// Sum of n numbers using formula, time complexity O(1)

// int fun(int n)
// {
//     return n*(n+1)/2;
// }
