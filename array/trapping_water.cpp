#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// n^2 solution
int max_water1(int A[], int n)
{
    int res = 0;
    for(int i=1; i<n-1; i++)
    {
        int left_max=A[i];
        for(int j=0; j<i; j++)
            left_max = max(left_max, A[j]);

        int right_max=A[i];
        for(int j=i+1; j<n; j++)
            right_max = max(right_max, A[j]);
        
        res = res + (min(left_max, right_max) - A[i]);
    }
    return res;
}

// n solution
int max_water2(int A[], const int n)
{
    vector<int> left_array(n, 0);
    vector<int> right_array(n, 0); 
    int res = 0;

    left_array[0] = A[0];
    for(int i=1; i<n; i++)
        left_array[i] = max(left_array[i-1], A[i]);

    right_array[n-1] = A[n-1];
    for(int i=n-2; i>=0; i--)
        right_array[i] = max(right_array[i+1], A[i]);

    for(int i=0; i<n; i++)
        res += (min(left_array[i], right_array[i]) - A[i]);
    
    return res;
}



int main()
{
    int A[] = {1,2,3,2,3,2,4,4};
    cout << max_water2(A, 8);
}