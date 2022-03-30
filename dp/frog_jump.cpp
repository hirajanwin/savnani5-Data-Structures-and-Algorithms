#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int solve(int ind, vector<int>& heights, vector<int>& dp) {
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left = solve(ind-1, heights, dp) + abs(heights[ind]-heights[ind-1]);
    int right = INT_MAX;
    if(ind>1)
        right = solve(ind-2, heights, dp) + abs(heights[ind]-heights[ind-2]);
    return dp[ind] = min(left, right);
}

// Space optimization can be donne from O(n) --> O(k) == use a queue == not necessary if k is big
int ksolve(int ind, int k, vector<int>& heights, vector<int>& dp) {
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int mini = INT_MAX;
    for(int i=1; i<=k; i++) {
        int res = INT_MAX;
        if(ind>=i) {
            res = solve(ind-i, heights, dp) + abs(heights[ind]-heights[ind-i]);
        }
        mini = min(mini, res);
    }
    return dp[ind] = mini;
}

int main() {
    int k = 3;
    vector<int> heights = {10,20,40,30,10,60};
    vector<int> dp(heights.size(), -1);
    dp[0] = 0; 
    cout << ksolve(heights.size()-1, k, heights, dp);
} 

