#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

// Interleave first half with second half
int main()
{
    int n=10;                                //Can be even only !!
    // int A[n] = {1,2,3,4};
    int A[n] = {11,12,13,14,15,16,17,18,19,20};
    queue<int> Q, NQ;
    for(int i=0; i<n; i++)
        Q.push(A[i]);
    
    stack<int> S1, S2;
    for(int i=0; i<n; i++)
    {
        if(i<n/2)
            S1.push(A[i]);
        else
            S2.push(A[i]);
    }

    for(int i=n-1; i>=0; i-=2)
    {
        A[i] = S2.top();
        S2.pop();
        A[i-1] = S1.top();
        S1.pop();
    }

    for(int i=0; i<n; i++)
    {
        NQ.push(A[i]);
        cout << A[i] << " ";
    }
}
