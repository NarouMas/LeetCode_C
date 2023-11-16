#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());
        string res = "";
        for(int i = 0; i < nums.size(); i++)
        {
            int num = 0, base = 1;
            for(int j = nums[i].size() - 1; j >= 0; j--)
            {
                if(nums[i][j] == '1')
                    num += base;
                base *= 2;
            }
            if(num != i)
            {
                while(i > 0)
                {
                    if(i % 2 == 0)
                        res = "0" + res;
                    else
                        res = "1" + res;
                    i /= 2;
                }
                while(res.size() < nums.size())
                    res = "0" + res;
                return res;
            }
        }
        for(int i = 0; i < nums.size(); i++)
            res += "1";
        return res;
    }
};

int main()
{
    vector<string> arr1 = {"111","011","001"};
    vector<string> arr2 = {"01","10"};
    vector<string> arr3 = {"00","01"};
    Solution sol;

    cout<<sol.findDifferentBinaryString(arr1)<<"\n";
    cout<<sol.findDifferentBinaryString(arr2)<<"\n";
    cout<<sol.findDifferentBinaryString(arr3)<<"\n";
}