#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res(l.size());
        for(int i = 0; i < l.size(); i++)
        {
            if(r[i] - l[i] <= 1)
            {
                res[i] = true;
                continue;
            }
            vector<int> temp(r[i] - l[i] + 1);
            for(int j = l[i], k = 0 ; j <= r[i]; j++, k++)
                temp[k] = nums[j];
            sort(temp.begin(), temp.end());
            int diff = temp[1] - temp[0];
            bool same = true;
            for(int j = 2; j < temp.size(); j++)
            {
                if(temp[j] - temp[j - 1] != diff)
                {
                    same = false;
                    break;
                } 
            }
            res[i] = same;
        }
        return res;
    }
};

int main()
{
    vector<int> arr1 = {4,6,5,9,3,7};
    vector<int> l1 = {0,0,2};
    vector<int> r1 = {2,3,5};
    vector<int> arr2 = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
    vector<int> l2 = {0,1,6,4,8,7};
    vector<int> r2 = {4,4,9,7,9,10};
    Solution sol;

    sol.checkArithmeticSubarrays(arr1, l1, r1);
    sol.checkArithmeticSubarrays(arr2, l2, r2);
}