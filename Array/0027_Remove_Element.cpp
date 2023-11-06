#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        int end = nums.size() - 1, ans = 0;
        int i = 0;
        for(; i <= end; i++)
        {
            if(nums[i] == val)
            {
                int j = end;
                for(; j > i && nums[j] == val; j--);
                if(j > i)
                {
                    ans++;
                    nums[i] = nums[j];
                }
                end = j - 1;
            }
            else
                ans++;
        }
        return ans;
    }
};

int main()
{
    vector<int> arr1 = {3,2,2,3};
    vector<int> arr2 = {0,1,2,2,3,0,4,2};
    vector<int> arr3 = {1};
    Solution sol;

    int ans = sol.removeElement(arr1, 3);
    cout<<ans<<endl;
    for(int i = 0; i < ans; i++)
        cout<<arr1[i]<<" ";
    cout<<endl;

    ans = sol.removeElement(arr2, 2);
    cout<<ans<<endl;
    for(int i = 0; i < ans; i++)
        cout<<arr2[i]<<" ";
    cout<<endl;

    ans = sol.removeElement(arr3, 1);
    cout<<ans<<endl;
    for(int i = 0; i < ans; i++)
        cout<<arr3[i]<<" ";
    cout<<endl;
}