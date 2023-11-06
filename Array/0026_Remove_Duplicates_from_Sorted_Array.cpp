#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> set;
        int i = 0, j = 0;
        while(j < nums.size())
        {
            if(set.count(nums[j]) == 0)
            {
                set.insert(nums[j]);
                nums[i] = nums[j];
                i++, j++;
            }
            else
            {
                j++;
            }
        }
        return i;
    }
};

int main()
{
    int ans;
    vector<int> arr1 = {0,0,1,1,1,2,2,3,3,4};
    vector<int> arr2 = {1,1,2};
    Solution sol;

    ans = sol.removeDuplicates(arr1);
    cout<<ans<<"\n";
    for(int i = 0; i < ans; i++)
        cout<<arr1[i]<<" ";
    cout<<"\n";

    ans = sol.removeDuplicates(arr2);
    cout<<ans<<"\n";
    for(int i = 0; i < ans; i++)
        cout<<arr2[i]<<" ";
    cout<<"\n";
}