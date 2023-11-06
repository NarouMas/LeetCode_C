#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        m--, n--;
        while(index >= 0)
        {
            if(m >= 0 && n >= 0)
            {
                if(nums1[m] > nums2[n])
                    nums1[index--] = nums1[m--];
                else
                    nums1[index--] = nums2[n--];
            }
            else if(n >= 0)
                nums1[index--] = nums2[n--];
            else
                index = -1;
        }
        return;
    }
};

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    Solution sol;
    sol.merge(nums1, 3, nums2, 3);
    for(int i = 0; i < nums1.size(); i++)
        cout<<nums1[i]<<" ";
}