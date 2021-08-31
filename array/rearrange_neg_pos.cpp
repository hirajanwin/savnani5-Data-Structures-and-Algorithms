#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;


void swap(int &a, int &b)
{
    int temp = a;
    a=b;
    b=temp;
}

int main()
{
    int n=9;
    int A[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int i=0, j=n-1;

    while(i<j)
    {
        if(A[i]<0 && A[j]>=0)
        {    
            i++;
            j--;
        }
        else if(A[i]<0 && A[j]<0)
            i++;
        else if(A[i]>0 && A[j]>=0)
            j--;
        else
        {
            swap(A[i], A[j]);
            i++;
            j--;
        }    
    }
    for(int i=0; i<n; i++)
    {
        cout << A[i] << " ";
    }
}
