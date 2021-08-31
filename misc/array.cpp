#include <iostream>
#include <stdio.h>

using namespace std;

// We cannot initialize variable sized arrays
 
int main()
{
    int A[10] = {2,3,4,5};

    for (auto x:A)
    {
        cout << x << endl; 
    }

}