#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

void print(int i, vector<int>& ds, vector<int> sub, int n)
{
    if(i==n)
    {
        for(auto it: ds)
            cout << it << " ";
        if(ds.size()==0)
            cout << "{}";
        cout << endl;
        return;
    }
    ds.push_back(sub[i]);
    print(i+1, ds, sub, n);
    ds.pop_back();
    print(i+1, ds, sub, n);
}

int main()
{
    int n = 3;
    vector<int> sub{3,2,1};
    vector<int> ds;
    print(0, ds, sub, n);
    return 0;
}