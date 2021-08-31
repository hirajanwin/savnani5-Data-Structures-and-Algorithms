// Find a pair with sum 10
#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

// O(n2) approach
// int main()
// {
//     int A[10] = {6,3,8,10,16,7,5,2,9,14};
//     for(int i=0; i<10; i++)
//     {
//         if(A[i]!=-1)
//             for(int j=i+1; j<10; j++)
//             {
//                 if(A[i]+A[j]==10)
//                 {
//                     cout << i << " " << j << endl;
//                     A[i],A[j] = -1,-1;
//                     break;
//                 }
//             }
//     }
// }

// Using Hashing: O(n) approach
// int main()
// {
//     int A[10] = {6,3,8,10,16,7,5,2,9,14};
//     int sum=10;
//     int max=A[0];   
//     for(int i=0; i<10; i++)
//     {
//         if(A[i]>max)
//             max = A[i];    
//     }
//     int B[max] = {0};
//     for(int i=0; i<10; i++)
//     {
//         B[A[i]]++;
//     }
//     for(int i=0; i<max; i++)
//     {
//         if(B[i]!=-1)
//         {
//             if((B[i]==1 && B[sum-i]==1 && (i!=sum-i)) || (B[i]==2 && (i=sum-i)))
//                 cout << i << " "<< sum-i << endl;
//                 B[i], B[sum-i] = -1,-1;
//         }
//     }
// }

//TC: O(n) Code for sorted array
// int main()
// {
//     int A[10] = {1,3,4,5,6,8,9,10,12,14};
//     int i=0, j=9, sum=10;
//     while(i<j)
//     {
//         if(A[i]+A[j]==sum)
//         {
//             cout << A[i] << " "<< A[j] << endl;
//             i++, j--;
//         }
//         else if(A[i]+A[j]<sum)
//             i++;
//         else
//             j--;
//     }
// }

// Leetcode style solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>result;
        unordered_map<int,int>tore;
        for(int i=0;i<nums.size();i++)
        {
            if(tore.find(target-nums[i])!=tore.end())
            {
                result.push_back(tore[target-nums[i]]);
                result.push_back(i);
                return result;
            }
            tore[nums[i]]=i;
        }
        return result;
    }
};

int main()
{
    vector<int> nums{1,3,4,5,6,8,9,10,12,14}, res;
    Solution s;
    res = s.twoSum(nums, 10);
    for(auto x:res)
        cout << x << " ";
}
