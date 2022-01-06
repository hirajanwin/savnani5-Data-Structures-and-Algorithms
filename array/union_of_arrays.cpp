#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

int doUnion(int a[], int n, int b[], int m)  {
    //code here
    set<int>s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    return s.size();
    }

int main()
{
    int n=5,m=3;
    int a[5] = {1,2,3,4,5}; 
    int b[3] = {7,3,4};
    cout << doUnion(a,n,b,m);

}