#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

void combo(int ind, int& sum, vector<int> arr, vector<int>& ds){
    if(ind==arr.size()){
        if(sum==0){
            for(auto it: ds){
                cout << it << " ";
            }
            cout << endl;
            return;
        }
    }
    ds.push_back(arr[ind]);
    sum -= arr[ind];
    combo(ind+1, sum, arr, ds);
    ds.pop_back();
    sum += arr[ind];
    combo(ind+1, sum, arr, ds);
}

int main()
{
    int sum = 7;
    vector<int> arr{2,3,6,7};
    vector<int> ds;
    combo(0, sum, arr, ds);
}