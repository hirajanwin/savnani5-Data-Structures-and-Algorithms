#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> t(102, vector<int>(102,-1));

int max(int a, int b) { return (a > b) ? a : b; }

// Recurssion + Memoization
int Knapsack(vector<int> wt, vector<int> val, int n, int W)
{
    if(n==0 || W==0)
        return 0;

    if(t[n][W]!=-1) 
        return t[n][W];

    if(wt[n-1] <= W) 
        return t[n][W] = max(val[n-1] + Knapsack(wt, val, n-1, W-wt[n-1]), Knapsack(wt, val, n-1, W));
    else
        return t[n][W] = Knapsack(wt, val, n-1, W);
}

int main()
{
    int n=4;
    vector<int> wt = {1,3,4,5};
    vector<int> val = {1,4,5,7};
    int W = 7;
    cout << Knapsack(wt, val, n, W);
} 