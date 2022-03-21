#include <iostream>
#include <stdio.h>

using namespace std;

// Summary of heap sort - 
// insert - insert at end to maitain complete binary tree and swap with parents till the max/min heap condition satisfies
// delete - delete the root and replace it with the last element in the tree and delete that element. Then swap with children till the max/min heap condition satisfies 
// insert elements and delete them and after deletion just add them at end of array

void insert(int* H, int n)
{
    int temp, i=n;
    temp = H[i];
    while(i > 1 && temp > H[i/2])
    {
        H[i] = H[i/2];
        i = i/2;
    }
    H[i] = temp;
}

int Delete(int* H, int n)
{
    int i,j, val;
    val = H[1];
    H[1] = H[n];
    H[n] = val;
    i=1; j=2*i;
    
    while(j < n-1)
    {
        if(H[j+1] > H[j])
            j=j+1;
        if(H[i] < H[j])
        {
            swap(H[i], H[j]);
            i = j;
            j = 2*j;
        }
        else
            break;
    } 
    return val;
}

int main()
{
    const int n=8;
    int H[n] = {0, 10, 20, 30, 25, 5, 40, 35};

    // Insert elements from index = 2, coz 0th index is dummy, assume 1st index is the starting heap!  
    for(int i=2; i<n; i++)
        insert(H,i);

    for(int i=7; i>1; i--)
        Delete(H,i);

    for(int i=1; i<=7; i++)
        cout << H[i] << " ";

    return 0;
}