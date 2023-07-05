#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int front = 0, back = nums.size() - 1, middle = (front + back) / 2;
        if(target < nums[0])
            return 0;
        if(target > nums[nums.size() - 1])
            return nums.size();
        while(back >= front)
        {
            if(nums[middle] == target)
                return middle;
            else if(nums[middle] < target && nums[middle + 1] > target)
                return middle + 1;
            else if(target > nums[middle])
            {
                front = middle + 1;
            }
            else if(target < nums[middle])
            {
                back = middle - 1;
            }
            middle = (front + back) / 2;
        }
        return -1;
    }
};

int main()
{
    Solution test;
    vector<int> nums = {1, 3, 5, 6, 8, 11, 15, 19, 30, 35, 40};
    cout << test.searchInsert(nums, 5) << endl;
    cout << test.searchInsert(nums, 2) << endl;
    cout << test.searchInsert(nums, 7) << endl;
    cout << test.searchInsert(nums, 0) << endl;
    cout << test.searchInsert(nums, 16) << endl;
    cout << test.searchInsert(nums, 14) << endl;
    cout << test.searchInsert(nums, 11) << endl;
    cout << test.searchInsert(nums, 36) << endl;
    return 0;
}