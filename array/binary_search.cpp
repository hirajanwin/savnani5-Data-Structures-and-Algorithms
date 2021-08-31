#include <iostream>
#include <stdio.h>
using namespace std;

int BinarySearch(int *A, int length, int key)
{
    int l=0,h=length-1, m;
    while(l<=h)
    {
        m = (l+h)/2;
        if(key==A[m])
        {
            return m;
        }
        else if(key<A[m])
        {
            h = m-1;
        }
        else
        {
            l = m+1;
        }
    }
    return -1;
}


int main()
{
    int A[5] = {3,4,10,12,20};
    cout << BinarySearch(A, 5, 4);
}