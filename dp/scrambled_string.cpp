#include <iostream>
#include <vector>
#include <cstring> 
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
 
unordered_map<string,int>mp;

bool scrambled(string x, string y)
{
    if(x.compare(y)==0)
        return true;

    // Both have same length
    if(x.length()<=1)
        return false;
    
    // Key generation and search in map
    string t = x+" "+y;
    
    if(mp.find(t)!=mp.end())
        return mp[t];

    int n = x.length();

    bool flag = false;
    for(int i=1; i<=n-1; i++)
    {
        if( // Condition 1 - Swap
            (scrambled(x.substr(0,i), y.substr(n-i,i)) &&
            scrambled(x.substr(i, n-i), y.substr(0,n-i))) ||
            // Condition 2 - No Swap
            (scrambled(x.substr(0,i), y.substr(0,i)) &&
            scrambled(x.substr(i, n-i), y.substr(i,n-i)))
        ){
            flag = true;
            break;
        }
    }
    return mp[t] = flag;
}


int main()
{
    mp.clear();
    string x = "great";
    string y = "eatgr";

    if(x.length()!=y.length())
        cout << false;  
    else if(x.length()==0 && y.length()==0)
        cout << true;
    else
        cout << scrambled(x,y);
}