#include <stdio.h>
#include <iostream>

using namespace std;


int min(long long a, long long b)
{
    if(a<b)
        return a;
    return b;
}

int main(){
    int sum = 0;
    long long array[1001][3];
    int dp[1001][3];
 
    int index[3];
    int n;
    scanf("%d",&n);
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<3;j++){
            scanf("%d",&array[i][j]);
        }
    }
    
    dp[0][0] = array[0][0];
    dp[0][1] = array[0][1];
    dp[0][2] = array[0][2];

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(j==0)
            {
                dp[i][j] = array[i-1][j] + min(dp[i][1], dp[i][2]);
            }
            else if(j==1)
            {
                dp[i][j] = array[i-1][j] + min(dp[i][0], dp[i][2]);
            }
            else
            {
                dp[i][j] = array[i-1][j] + min(dp[i][0], dp[i][1]);
            }
        }
    }


    int min = INT_MAX;
    for(int i=0; i<3; i++)
    {
        if(dp[n-1][i] < min)
            min = dp[n-1][i];
    }
    cout << min;

}
