#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)

    int flag_a=0;         // for one character string
    int flag_b=0;

    char s_init = S[0];
    for(int i=1; i<S.size(); i++)
    {
        if(s_init=='a' &&  S[i]!=s_init)
        {
            flag_b=1;
            s_init = 'b';
        }
        else if(s_init=='b' && S[i]!=s_init)
        {
            flag_a=1;
            s_init = 'a';
        }
    }
    if(flag_a==0 && flag_b==0)
        return true;
    else if(flag_a==0 && flag_b==1)
        return true;
    else if(flag_a==1 && flag_b==0)
        return false;
    else
        return false;
}

int main()
{
    string s = "aaba";
    cout << solution(s);
}