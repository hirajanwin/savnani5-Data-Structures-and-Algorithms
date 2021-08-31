#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char A[] = "ABCDE";
    char B[] = "CEDAB";
    int i,j=0;
    for(i=0; i<5; i++)
    {
        if(A[i]==B[0])
            break;    
    }
    while(B[j]!='\0')
    {
        if(A[i]=='\0')
            i=0;
        if(A[i]!=B[j])
        {
            cout << "False";
            return 0;
        }
        i++;j++;
    }
    cout << "True";
}