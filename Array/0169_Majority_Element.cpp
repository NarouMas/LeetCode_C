#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int half = nums.size() / 2;
        for(int n : nums)
        {
            if(map.find(n) == map.end())
                map[n] = 1;
            else
                map[n]++;
        }
        for(auto &n : map)
        {
            if(n.second > half)
                return n.first;
        }
        return -1;
    }
};
int main()
{
    vector<int> arr1 = {3,2,3};
    vector<int> arr2 = {2,2,1,1,1,2,2};
    Solution sol;

    cout<<sol.majorityElement(arr1)<<"\n";
    cout<<sol.majorityElement(arr2)<<"\n";
}