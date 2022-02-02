#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int> &A, int l, int m, int h)
{
    int i=l; int k=l; int j=m+1;
    
    vector<int> B(A.size(),0);
    while(i<=m && j<=h)
    {
        if(A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    // Copy remaining elements
    for(; i<=m; i++)
        B[k++] = A[i];
    for(; j<=h; j++)
        B[k++] = A[j];
    
    // Copy array A to B
    for(int i=l; i<=h; i++)
        A[i] = B[i];
}


void mergesort(vector<int> &A, int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        mergesort(A, l, mid);
        mergesort(A, mid+1, h);
        merge(A, l, mid, h);
    }
}


int main()
{
    vector<int> A = {10, 40, 50, 100, 30, 20};
    int n = A.size();
    mergesort(A, 0, n-1);
    for(int i=0; i<n; i++)
        cout << A[i] << " " ;
}