#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *p1, *p2, res;
        unordered_set<int> set;
        p1 = (nums1.size() < nums2.size()) ? &nums1: &nums2;
        p2 = (nums1.size() < nums2.size()) ? &nums2: &nums1;
        for(int n: *p1)
            set.insert(n);
        for(int n: *p2)
            if(set.count(n))
            {
                res.push_back(n);
                set.erase(n);
            }
                
        return res;
    }
};