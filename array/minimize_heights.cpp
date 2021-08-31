#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int getMinDiff(int arr[], int n, int k) {
        // code here
        int i, low, high, res;
        sort(arr, arr+n);
        low = arr[0] + k;
        high = arr[0] + k;
        
        for(i=0; i<n; i++)
        {
            if(arr[i] < k)
                high = arr[i] + k;
            else
                break;
        }
        
        for(int j=n-1; j>=i; j--)
        {
            int temp_high = arr[j] + k;
            int temp_low = arr[j] - k;
            
            if(temp_low <= high)
            {
                if(temp_high - low <= high - temp_low)
                {
                    if(temp_high > high)
                        high = temp_high;
                }
                else
                {
                    if(temp_low < low)
                        low = temp_low;
                }
            }
            else
                high = temp_low;
        }
        
        res = high - low;    
        
        return res;
}

int main()
{
    int A[] = {1,5,8,10};
    cout << getMinDiff(A, 4, 2);
}
