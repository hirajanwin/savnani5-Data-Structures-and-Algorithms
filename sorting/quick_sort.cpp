#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &A, int l, int h)
{
    int pivot = A[l];
    int i=l; 
    int j=h;
    
    do
    {
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if(i<j)
            swap(A[i], A[j]);

    }while(i<j);
    swap(A[l], A[j]);
    return j;
}

void quicksort(vector<int> &A, int l, int h)
{
    if(l<h)
    {
        int j = partition(A, l, h);
        quicksort(A, l, j);
        quicksort(A, j+1, h);
    }
}  


int main()
{
    vector<int> A = {10, 40, 50, 100, 30, 20, INT_MAX};
    int n = A.size()-1;
    quicksort(A, 0, n);
    for(int i=0; i<n; i++)
        cout << A[i] << " " ;
}