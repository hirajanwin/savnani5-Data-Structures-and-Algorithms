#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isBalanced(string s)
    {
        vector<int> cap(26,0);
        vector<int> small(26,0);
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] - 'A' >= 0 && s[i] - 'A' < 26)
                cap[s[i] - 'A'] = 1;
            else if(s[i] - 'a' >= 0 && s[i] - 'a' < 26)
                small[s[i] - 'a' ] = 1;
        }
        
        for(int i=0; i<cap.size(); i++)
        {
            if(cap[i]!=small[i])
                return false;
        }
        return true;
    }
    
    string longestNiceSubstring(string s) {
        int max_len=0;
        string lns= "";
        for(int i=0; i<s.size(); i++)
        {
            for(int j=i; j<s.size(); j++)
            {
                string sub = s.substr(i,j+1-i);
                if(isBalanced(sub))
                {
                    if(j+1-i > max_len)
                    {
                        max_len = j+1-i;
                        lns = sub;
                    }
                }
                     
            }
        }
        return lns;
    }


int main()
{
    string s = "FeOZJEnNfjz";
    cout << longestNiceSubstring(s);
}