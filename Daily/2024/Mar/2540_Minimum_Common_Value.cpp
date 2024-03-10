#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int a = 0, b = 0;
        while(a < nums1.size() && b < nums2.size())
        {
            if(nums1[a] == nums2[b])
                return nums1[a];
            while(b < nums2.size() && nums1[a] > nums2[b])
                b++;
            if(b >= nums2.size())
                break;
            while(a < nums1.size() && nums1[a] < nums2[b])
                a++;
        }
        return -1;
    }
};