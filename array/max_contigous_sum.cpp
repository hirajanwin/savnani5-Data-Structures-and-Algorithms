// Initialize:
//     max_so_far = INT_MIN
//     max_ending_here = 0

// Loop for each element of the array
//   (a) max_ending_here = max_ending_here + a[i]
//   (b) if(max_so_far < max_ending_here)
//             max_so_far = max_ending_here
//   (c) if(max_ending_here < 0)
//             max_ending_here = 0
// return max_so_far


// Base idea: It accumulates positive integers and doesn't allow accumulation of negative integers

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n = 6;
    int A[n] = {-3, 2, -5, 6, 2, -5};
    int max_ending_here=0, max_so_far=INT_MIN;
    for(int i=0; i<n; i++)
    {
        max_ending_here = max_ending_here + A[i];
        if(max_ending_here > max_so_far)
            max_so_far = max_ending_here;
        if(max_ending_here < 0)
            max_ending_here = 0;
    }
    cout << max_so_far;
}