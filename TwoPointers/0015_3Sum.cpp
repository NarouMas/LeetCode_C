#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size() && nums[i] <= 0)
        {
            int left = i + 1, right = nums.size() - 1;
            int I = nums[i];
            while(left < right)
            {
                int L = nums[left], R = nums[right];
                if(nums[i] + nums[left] + nums[right] == 0)
                {
                    vector<int> entry(3);
                    entry[0] = nums[i], entry[1] = nums[left], entry[2] = nums[right];
                    res.push_back(entry);
                    do
                    {
                        left++;
                    }while(left < right && nums[left] == L);
                    do
                    {
                        right--;
                    }while(left < right && nums[right] == R);
                }
                else if(nums[i] + nums[left] + nums[right] < 0)
                {
                    do
                    {
                        left++;
                    }while(left < right && nums[left] == L);
                }
                else
                {
                    do
                    {
                        right--;
                    }while(left < right && nums[right] == R);
                }
            }
            do
            {
                i++;
            } while (i < nums.size() && nums[i] == I);
            
        }
        return res;
    }
};

int main()
{
    vector<int> arr1 = {-1,0,1,2,-1,-4};
    Solution sol;

    vector<vector<int>> res = sol.threeSum(arr1);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<"\n";
}