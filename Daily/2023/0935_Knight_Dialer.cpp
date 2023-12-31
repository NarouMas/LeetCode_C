#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        vector<long long> nums(10, 1);
        int res = 0;
        if(n > 1)
            nums[5] = 0;
        for(int i = 2; i <= n; i++)
        {
            vector<long long> temp = nums;
            nums[0] = (temp[4] + temp[6]) % 1000000007;
            nums[1] = (temp[6] + temp[8]) % 1000000007;
            nums[2] = (temp[7] + temp[9]) % 1000000007;
            nums[3] = (temp[4] + temp[8]) % 1000000007;
            nums[4] = (temp[0] + temp[3] + temp[9]) % 1000000007;
            nums[6] = (temp[0] + temp[1] + temp[7]) % 1000000007;
            nums[7] = (temp[2] + temp[6]) % 1000000007;
            nums[8] = (temp[1] + temp[3]) % 1000000007;
            nums[9] = (temp[2] + temp[4]) % 1000000007;
        }
        for(int i = 0; i < 10; i++)
            res = (res + nums[i]) % 1000000007;
        return res;
    }
};

int main()
{
    Solution sol;
    cout<<sol.knightDialer(1)<<"\n";
    cout<<sol.knightDialer(2)<<"\n";
    cout<<sol.knightDialer(3)<<"\n";
    cout<<sol.knightDialer(4)<<"\n";
    cout<<sol.knightDialer(5)<<"\n";
    cout<<sol.knightDialer(6)<<"\n";
    cout<<sol.knightDialer(3131)<<"\n";

    /*
    10
    20
    46
    104
    240
    */
}