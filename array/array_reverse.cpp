#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int i=0, temp, n = 7;
    int A[n] = {1,2,3,4,5,6,7};
    
    while(i<n-i-1)
    {
        temp = A[i];
        A[i] = A[n-i-1];
        A[n-i-1] = temp;  
        i++;
    }
    for(int i=0; i<n; i++)
    {
        cout << A[i] << " ";
    }

}

// Alternate method will be to iterate the arrray from backwards and store it in new array forward