#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> map;
        int res = 0, m = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int n = nums[i], rev = 0;
            while (n > 0)
                rev *= 10, rev += n % 10, n /= 10;
            rev = nums[i] - rev;
            
            if(map.find(rev) != map.end())
                map[rev]++;
            else
                map[rev] = 1;
            m = max(m, map[rev]);
        }
        vector<int> dp(m + 1, 0);
        for(int i = 2; i < m + 1; i++)
            dp[i] = (dp[i - 1] + i - 1) % (1000000000 + 7);
        for(auto it : map)
        {
            if(it.second > 1)
                res += dp[it.second], res %= (1000000000 + 7);
        }

        return res;
    }
};

int main()
{
    vector<int> arr1 = {42,11,1,97};
    vector<int> arr2 = {13,10,35,24,76};
    Solution sol;

    cout<<sol.countNicePairs(arr1)<<"\n";
    cout<<sol.countNicePairs(arr2)<<"\n";
}