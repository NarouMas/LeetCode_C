#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int n: nums)
        {
            if(set.count(n))
                return n;
            set.insert(n);
        }
        return -1;
    }
};