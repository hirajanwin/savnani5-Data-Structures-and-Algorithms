#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

bool isHappy(int n) {
        
    vector<int> num_store;
    while(1)
    {
        int new_num=0;
        while(n >= 1)
        {
            int digit = n%10;
            new_num += pow(digit,2); 
            n = n/10;
        } 
        if(new_num==1)
            return true;
        else
        {
            for(int x: num_store)
            {
                if(new_num==x)
                    return false;
            }
            num_store.push_back(new_num);
            n = new_num;
        }
    }
}

int main()
{
    int n = 19;
    cout << isHappy(n);
}