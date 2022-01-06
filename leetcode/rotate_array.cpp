#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    
    void rotate(vector<int>& nums, int k) {
        if(k==0)
            return;

        while(k > nums.size())
            { k = k - nums.size(); }

        int i=0, start = nums.size()-k;
        int j = start;
        while(i < j)
        {
            swap(nums[i], nums[j]);    
            i++;
            j = start + (i%k);  
        }
        if(i > j && nums.size()%2 != 0)
        {
            while(i != nums.size()-1)
            {
                swap(nums[i], nums[nums.size()-1]);
                i++;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
    int k = 29;
    s.rotate(nums, k);
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
    
}