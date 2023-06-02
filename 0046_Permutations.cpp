#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do{
            res.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return res;
    }
    // void foo(vector<int>& nums, vector<int> buffer)
    // {
    //     if(buffer.size() == nums.size())
    //     {
    //         res.push_back(buffer);
    //         return;
    //     }
    //     for(int i = 0; i < nums.size(); i++)
    //     {
    //         bool in = false;
    //         for(int j = 0; j < buffer.size(); j++)
    //         {
    //             if(buffer[j] == nums[i])
    //             {
    //                 in = true;
    //                 break;
    //             }
    //         }
    //         if(!in)
    //         {
    //             buffer.push_back(nums[i]);
    //             foo(nums, buffer);
    //             buffer.pop_back();
    //         }
    //     }
    // }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res;
    res = sol.permute(nums);
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
}