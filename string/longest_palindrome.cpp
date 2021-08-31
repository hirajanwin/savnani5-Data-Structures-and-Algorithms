// #include <iostream>
// #include <stdio.h>
// #include <bits/stdc++.h>

// using namespace std;

// string longestPalin(string S)    
// {
//     // code here
//     int n = S.length();
//     string longest = "";
//     int a, b;
//     for(int i=0; i<n; i++)
//     {
//         a = i;
//         for(int j=n-1; j>=a; j--)
//         {
//             b = j;
//             if(S[a]==S[j])
//             {
//                 longest += S[a];
//                 a++;                    
//             }
//             else
//                 longest = "";
//         }
//         if(longest != "")
//             longest = longest + S.substr(a,j);
//     }
//     return S;
// }

// int main()
// {

// }