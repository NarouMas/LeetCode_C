#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        vector<string> strs = {s1, s2, s3};
        int same1 = 0, same2 = 0, same, res = 0;
        for(int i = 1; i < 3; i++)
        {
            if(i == 1)
            {
                for(int j = 0 , k = 0; j < strs[i - 1].size() && k < strs[i].size(); j++, k++)
                {
                    if(strs[i - 1][j] == strs[i][k])
                        same1++;
                    else
                        break;
                }
            }
            else
            {
                for(int j = 0 , k = 0; j < strs[i - 1].size() && k < strs[i].size(); j++, k++)
                {
                    if(strs[i - 1][j] == strs[i][k])
                        same2++;
                    else
                        break;
                }
            }
        }
        same = min(same1, same2);
        if(same == 0)
            return -1;
        for(int i = 0; i < 3; i++)
            res += strs[i].size() - same;
        return res;
    }
};

int main()
{
    Solution sol;
    cout<<sol.findMinimumOperations("abc", "abb", "ab")<<"\n";  //2
    cout<<sol.findMinimumOperations("dac", "bac", "cac")<<"\n"; //-1
    cout<<sol.findMinimumOperations("oby", "obz", "obf")<<"\n"; //3
    cout<<sol.findMinimumOperations("cc", "cccb", "c")<<"\n"; //4
    return 0;
}