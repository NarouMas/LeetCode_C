#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> jumps(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            int j = (i + nums[i] < nums.size()) ? i + nums[i] : nums.size() - 1;
            for(; jumps[j] == 0 && j > 0; j--)
                jumps[j] = jumps[i] + 1;
            
        }
        return jumps[nums.size() - 1];
    }
};

int main()
{
    vector<int> arr1 = {2,3,1,1,4};
    vector<int> arr2 = {2,3,0,1,4};
    Solution sol;

    cout<<sol.jump(arr1)<<"\n";
    cout<<sol.jump(arr2)<<"\n";
}