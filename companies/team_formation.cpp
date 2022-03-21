#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void combination(int ind, int minplayers, vector<int> allowed, vector<int>& ds, int& count) {
    if(ind==allowed.size()) {
        if(ds.size()>=minplayers) {
            count++;
        }
        return;
    }
    ds.push_back(allowed[ind]);
    combination(ind+1, minplayers, allowed, ds, count);
    ds.pop_back();
    combination(ind+1, minplayers, allowed, ds, count);
}


int main() {
    vector<int> v{8, 4, 6, 13, 5, 10};
    int minplayers = 3;
    int minlevel = 4;
    int maxlevel = 10;

    vector<int> allowed;
    for(auto it:v){
        if(it>=minlevel && it<=maxlevel)
            allowed.push_back(it);  
    }   

    //   allowed = 4,6,8,5,10
    vector<int> ds;
    int count=0;
    combination(0, minplayers, allowed, ds, count);
    cout << count;
}