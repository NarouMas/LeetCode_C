#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> jump(nums.size(), false);
        jump[0] = true;
        for(int i = 0; i < nums.size(); i++)
        {
            if(jump[i])
            {
                int j = (i + nums[i] < nums.size()) ? i + nums[i] : nums.size();
                for(; !jump[j]; j--)
                    jump[j] = true;
            }
        }
        return jump[nums.size() - 1];
    }
};

int main()
{
    vector<int> arr1 = {2,3,1,1,4};
    vector<int> arr2 = {3,2,1,0,4};
    Solution sol;

    cout<<sol.canJump(arr1)<<"\n";
    cout<<sol.canJump(arr2)<<"\n";
}