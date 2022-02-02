#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return {};

        vector<vector<int>> threesum;
        unordered_map<int, int> umap;

        // Filling the map
        for(int i=0; i<nums.size(); i++)
        {
            if(umap.find(nums[i]) == umap.end())
                umap[nums[i]] = 1;
            else
                umap[nums[i]] +=1;
        }

        for(int i=0; i<nums.size(); i++)
        {
            umap[nums[i]] -=1;
            unordered_map<int, int>:: iterator itr;
            for (itr = umap.begin(); itr != umap.end(); itr++)
            {
                int flag=0;
                int twosum=0;
                if(itr->second!=0)
                {
                    twosum = nums[i] + itr->first;    
                    umap[itr->first] -=1;
                    if(umap.find(-twosum) != umap.end())
                    {
                        if(umap[-twosum] !=0)
                        {
                            vector<int> elements{nums[i], itr->first, -twosum};
                            sort(elements.begin(), elements.end());
                            for(auto vec: threesum)
                            {
                                if(vec==elements) {flag=1; break;}
                            }
                            if(flag==0)
                                threesum.push_back(elements);
                        }
                    }
                    umap[itr->first] +=1;
                }
            }
            umap[nums[i]] +=1;
        }
        return threesum;
    }

int main()
{
    vector<int> nums{-1,0,1,2,-1,-4};
    for(auto v: threeSum(nums))
        cout << v[0] << v[1] << v[2] << endl;
}
