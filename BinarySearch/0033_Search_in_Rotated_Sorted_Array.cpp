#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int front = 0, back = nums.size() - 1, middle;
        if(nums[0] == target)
            return 0;
        else if(nums[nums.size() - 1] == target)
            return nums.size() - 1;
        int res = find_res(nums, target, front, back);
        if(res >= 10000)
            return res - 10000;
        //cout<<"res is "<<res<<endl;
        if(res != 0 || (nums.size() > 1 && nums[0] > nums[1]))
        {
            if(target < nums[0])
                front = res + 1;
            else
                back = res - 1;
        }
        
        middle = (front + back) / 2;
        while(back >= front)
        {
            if(nums[middle] == target)
                return middle;
            if(nums[middle] > target)
                back = middle - 1;
            else if(nums[middle] < target)
                front = middle + 1;
            middle = (front + back) / 2;
        }
        return -1;
    }
private:
    int find_res(vector<int>& nums, int target, int front, int back)
    {
        int middle = (front + back) / 2;
        while(back >= front)
        {
            if(nums[middle] == target)
                return middle + 10000;
            if(middle > 0 && nums[middle] < nums[middle - 1])
                return middle;
            if(nums[middle] > nums[0])
            {
                front = middle + 1;
            }
            else
            {
                back = middle - 1;
            }
            middle = (front + back) / 2;
        }
        return 0;
    }
};

int main()
{
    Solution test;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << test.search(nums, 0) << endl;
    cout << test.search(nums, 3) << endl;
    cout << test.search(nums, 4) << endl;
    cout << test.search(nums, 5) << endl;
    cout << test.search(nums, 6) << endl;
    cout << test.search(nums, 7) << endl;
    cout << test.search(nums, 8) << endl;
    cout << test.search(nums, 1) << endl;
    cout << test.search(nums, 2) << endl;
    vector<int> nums_2 = {5, 1, 2, 3, 4};
    cout << test.search(nums_2, 3) << endl;
    return 0;
}