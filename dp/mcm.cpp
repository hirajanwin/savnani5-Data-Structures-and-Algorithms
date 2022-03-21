#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int t[100][100];

int solve(vector<int>& v, int i, int j)
{
    if(i>=j)
        return 0;
    if(t[i][j]!=-1)
        return t[i][j];

    int mn= INT_MAX;
    for(int k=i; k<j; k++)
    {
        int temp = solve(v, i, k) + solve(v, k+1, j) + v[i-1]*v[k]*v[j];
        if(temp < mn)
            mn = temp;
    }
    return t[i][j] = mn;
}


int main()
{
    int n = 5;
    vector<int> v{40,20,30,10,30};
    memset(t,-1,sizeof(t));
    cout << solve(v, 1, n-1);
}