#include <iostream>
#include <stdio.h>
using namespace std;

// NOTE: Arrays are always passed by address, they can't be passed by values at all
// Example of Passing an array
// void fun(int A[], int n)
// {
//     for(int i=0; i<n; i++)
//         printf("%d\n", A[i]);
// }

// int main()
// {
//     int A[5] = {2,4,6,8,10};
//     fun(A, 5);
// }

// Example of Returning an array (return type pointer)
int * fun(int n)
{
    int *p;
    p = new int[n];
    p[0] = 1; p[1] = 2; p[2] = 3; p[3] = 4; p[4] = 5;
    return p;
}

int main()
{
    int *A;
    A = fun(5);
    for (int i=0; i<5; i++)
        cout << A[i] << endl;
    return 0;
}