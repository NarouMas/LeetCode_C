#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            if(map.find(nums[i]) == map.end())
            {
                map[nums[i]] = 0;
                push(0, nums[i], res);
            }
            else
            {
                map[nums[i]]++;
                push(map[nums[i]], nums[i], res);
            }
        }
        return res;
    }
private:
    inline void push(int row, int v, vector<vector<int>>& res)
    {
        if(res.size() <= row)
        {
            vector<int> arr;
            res.push_back(arr);
        }
        res[row].push_back(v);
    }
};

int main()
{
    vector<int> arr1 = {1,3,4,1,2,3,1};
    Solution sol;

    sol.findMatrix(arr1);
}