#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void sort012(int a[], int n)
{
    int hash[3] = {0,0,0};
    int c=0;
    
    for(int i=0; i<n; i++)
    {
        hash[a[i]]++;
    }

    for(int i=0; i<3; i++)
    {
        int j = hash[i];
        for(int k=c; k<j+c; k++)
        {
            a[k] = i;
        }
        c=j+c;
    }
}

int main()
{
    int A[] = {0,2,1,2,0}; 
    sort012(A, 5);
}
