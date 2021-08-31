#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int i=0, temp, n=6;
    int A[n] = {1000, 11, 445,1, 330, 3000};
    int min=A[0], max=A[0];

    for(int i=1; i<n; i++)
    {
        if(A[i]>max)
            max = A[i];
        else if(A[i]<min)
            min = A[i];
    }
    cout << max << " " << min; 
}