#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<vector<int>> t(6, vector<int>(12,-1));

// Recurssion + Memoization
bool rsubsetsum(vector<int> arr, int n, int sum)
{
    if(n==0 && sum==0)
        return true;
    else if(n==0)
        return false;
    else if(sum==0)
        return true;

    if(t[n][sum]!=-1) 
        return t[n][sum];

    if(arr[n-1] <= sum)
        return t[n][sum] = rsubsetsum(arr, n-1, sum-arr[n-1]) || rsubsetsum(arr, n-1, sum);
    else
        return t[n][sum] = rsubsetsum(arr, n-1, sum);
}

// Iterative version - tabulation
bool isubsetsum(vector<int> arr, int n, int sum)
{
   for(int i=0; i<n+1; i++)
   {
       for(int j=0; j<sum+1; j++)
       {
           if(i==0) t[i][j] = false;
           if(j==0) t[i][j] = true;
       }
   }

   for(int i=1; i<n+1; i++)
   {
       for(int j=1; j<sum+1; j++)
       {
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
       }
   }
   return t[n][sum];
}


int main()
{
    int n=5;
    vector<int> arr = {2,3,8,7,10};
    int sum = 11;
    cout << rsubsetsum(arr, n, sum);
} 