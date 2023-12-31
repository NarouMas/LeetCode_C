#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int set = 1, cur = nums[0], res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != cur)
            {
                cur = nums[i];
                set++;
            }
            nums[i] = set;
        }
        for(int i = 0; i < nums.size(); i++)
            res += nums[i] - 1;
        return res;
    }
};

int main()
{
    vector<int> arr1 = {5,1,3};
    vector<int> arr2 = {1,1,1};
    vector<int> arr3 = {1,1,2,2,3};
    vector<int> arr4 = {8,2,6,9,4,6,7,7,8};
    Solution sol;

    cout<<sol.reductionOperations(arr1)<<"\n";
    cout<<sol.reductionOperations(arr2)<<"\n";
    cout<<sol.reductionOperations(arr3)<<"\n";
    cout<<sol.reductionOperations(arr4)<<"\n";
}