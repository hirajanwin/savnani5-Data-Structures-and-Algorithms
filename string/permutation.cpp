// Important question--please revisit

#include <iostream>
#include <stdio.h>
using namespace std;

// void perm1(char S[], int k)
// {
//     static int A[10]={0};
//     static char Res[10];
//     int i;

//     if(S[k]=='\0')
//     {
//         Res[k]='\0';
//         cout << Res;
//         cout << endl;
//     } 
//     else
//     {
//         for(i=0; S[i]!='\0'; i++)
//         {
//             if(A[i]==0)
//             {
//                 Res[k]=S[i];
//                 A[i]=1;
//                 perm1(S,k+1);
//                 A[i]=0;
//             }
//         }
//     }
// }

void swap(char S[], int a, int b)
{
    int temp = S[a];
    S[a] = S[b];
    S[b] = temp;
}

void perm2(char S[], int l, int h)
{
    int i;

    if(l==h)
    { 
        cout << S;
        cout << endl;
    } 
    else
    {
        for(i=l; i<=h; i++)
        {
           swap(S, l, i);
           perm2(S, l+1, h);
           swap(S, l, i);
        }
    }
}


int main()
{
    char S[] = "ABCD";
    perm2(S,0,3);
}