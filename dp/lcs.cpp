#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> t(102, vector<int>(102,-1));

int max(int a, int b) { return (a > b) ? a : b; }

template <class T>
int lcs(T x, T y, int m, int n)
{
    if(m==0 || n==0)
        return 0;

    if(t[m][n]!=-1) 
        return t[m][n];

    if(x[m-1] == y[n-1]) 
        return t[m][n] = 1 + lcs<T>(x,y,m-1,n-1);
    else
        return t[m][n] = max(lcs<T>(x,y,m,n-1), lcs<T>(x,y,m-1,n));
}

int lcstr(string x, string y, int m, int n)
{
    if(m==0 || n==0)
        return 0;

    if(t[m][n]!=-1) 
        return t[m][n];

    if(x[m-1] == y[n-1]) 
        return t[m][n] = 1 + lcstr(x,y,m-1,n-1);
    else
        return t[m][n] = 0;
}

string printLcs(string x, string y, int m, int n)
{
    int i=m; int j=n; string s = "";
    
    while(i>0 && j>0)
    {
        if(x[i-1] == y[j-1])
        {
            s.push_back(x[i-1]);   
            i--;j--;
        }
        else
        {
            if(t[i][j-1]>t[i-1][j])
                j--;
            else
                i--;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

int lps(string z)
{
    string og = z;
    reverse(z.begin(), z.end());
    return lcs<string>(og, z, og.length(), z.length());
}

string printScs(string x, string y, int m, int n)
{
    int count = lcs<string>(x,y,m,n);
    int i=m; int j=n; string scs="";

    while(i>0 && j>0)
    {
        if(x[i-1] == y[j-1])
        {
            scs.push_back(x[i]);
            i--;j--;
        }
        else
        {
            if(t[i][j-1] > t[i-1][j])
            {
                scs.push_back(y[j-1]);
                j--;
            }
            else if(t[i-1][j] > t[i][j-1])
            {
                scs.push_back(x[i-1]);
                i--;
            }
        }
    }
    while(i>0)
    {
        scs.push_back(x[i-1]);
        i--;
    }
    while(j>0)
    {
        scs.push_back(y[j-1]);
        j--;
    }
    reverse(scs.begin(), scs.end());
    return scs;
}

int lrs(string x, string y, int m, int n)
{
    if(m==0 || n==0)
        return 0;

    if(t[m][n]!=-1) 
        return t[m][n];

    if(x[m-1] == y[n-1] && m!=n) 
        return t[m][n] = 1 + lcs(x,y,m-1,n-1);
    else
        return t[m][n] = max(lcs(x,y,m,n-1), lcs(x,y,m-1,n));
}

int lis(vector<int> vec, int n)
{
    // Sort and remove duplicates from vector
    vector<int> og = vec;
    set<int> s(vec.begin(), vec.end());
    vec.assign(s.begin(), s.end());
    return lcs<vector<int>>(og, vec, og.size(), vec.size());
}


int main()
{
    string x = "abcdgh";
    string y = "abedfhr";
    string z = "agbcba";   
    int n = 8;
    vector<int> v{10,9,2,5,3,7,101,150,18};
    
    // cout << lcs<string>(x,y,x.length(),y.length()) << endl;
    // cout << printLcs(x,y,x.length(),y.length()) << endl;
    // cout << lps(z);
    cout << lis(v, n);
} 