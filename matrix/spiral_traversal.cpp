#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int r=3, c=4;
    vector<vector<int>> matrix = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}};
    vector<int> v;
    int i=0,j=-1,count = 0, ce=c, re=r, cs=-1, rs=1; 
    while(count < r*c)
    {
        j++;
        while(j<ce)
        {
            v.push_back(matrix[i][j]);
            count++;
            j++;
        }

        if(count>=r*c)
            break;
        ce--;
        j--;
        i++;

        while(i<re)
        {
            v.push_back(matrix[i][j]);
            count++;
            i++;
        }

        if(count>=r*c)
            break;

        re--;
        i--;
        j--;

        while(j>cs)
        {
            v.push_back(matrix[i][j]);
            count++;
            j--;
        }

        if(count>=r*c)
            break;
        
        cs++;
        j++;

        while(i>rs)
        {
            i--;
            v.push_back(matrix[i][j]);
            count++;
        }
        rs++;
    }

    for(auto x:v)
        cout << x << " ";
}