#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int t[100][100];

int solve(int e, int f)
{
    // Base condition
    if(e==1)
        return f;
    if(f==0||f==1)
        return f;
    if(t[e][f] != -1)
        return t[e][f];
    
    int mn = INT_MAX;
    for(int k=1;k<=f; k++)
    {
        int temp = 1 + max(solve(e-1, k-1), solve(e, f-k));
        mn = min(mn, temp);
    }
    return t[e][f] = mn;
}


int main()
{
    memset(t, -1, sizeof(t));
    int e=3; int f=5;
    cout << solve(e,f);
}   