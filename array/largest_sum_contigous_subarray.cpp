#include <iostream>
#include <stdio.h>
using namespace std;


// Kadane's algorithm--O(n) approach 
int main()
{
    int A[] = {-1,-2,-7,8,5,3,-6,2};
    int max_ending_here=0, max_so_far=0;

    for(int i=0; i< sizeof(A)/sizeof(A[0]); i++)
    {
        max_ending_here = max_ending_here + A[i];
        if(max_ending_here < 0)
            max_ending_here = 0;
        if(max_ending_here > max_so_far)
            max_so_far = max_ending_here;
    }
    cout << max_so_far;
}