#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findGrantsCap(vector<int>& salaries, int budget) {
    sort(salaries.begin(), salaries.end());
    float salaryCap = float(budget) / salaries.size();
    for(int i=0; i<salaries.size(); i++) {
        if(salaries[i] < salaryCap) {
            float overAllocated = salaryCap - salaries[i];
            float restOfSal = (salaries.size() - 1) - i;
            salaryCap += overAllocated/restOfSal;
        }
    }
    return salaryCap;
    }

int main() {
    int budget = 190;
    vector<int> arr = {2, 50, 120, 100, 1000};
    cout << findGrantsCap(arr, budget); 
}

// {1000, 120, 100, 50, 2}