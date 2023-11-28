#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256, 0);
        int left = 0, right = 0, res = 0;
        while(left < s.size() && right < s.size())
        {
            if(count[s[right]] == 0)
                count[s[right]]++, right++, res = max(res, right - left);
            else
                count[s[left]]--,left++;
            
        }
        return res;
    }
};

int main()
{
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    Solution sol;

    cout<<sol.lengthOfLongestSubstring(s1)<<"\n";
    cout<<sol.lengthOfLongestSubstring(s2)<<"\n";
    cout<<sol.lengthOfLongestSubstring(s3)<<"\n";
}