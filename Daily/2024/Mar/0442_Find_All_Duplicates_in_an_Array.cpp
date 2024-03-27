#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> set;
        vector<int> res;
        for(int n: nums)
        {
            if(set.count(n))
                res.push_back(n);
            else
                set.insert(n);
        }
        return res;
    }
};