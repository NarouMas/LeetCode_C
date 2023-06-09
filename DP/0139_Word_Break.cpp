#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for(int i = 1; i < s.length() + 1; i++)
            for(int j = 0; j < i; j++)
            {
                if(dp[j] && dict.count(s.substr(j, i - j)) != 0)
                {
                    dp[i] = true;
                    break;
                }
            }   
        return dp[s.length()];
    }
};

int main()
{
    Solution sol;
    vector<string> dict1 = {"leet","code"};
    vector<string> dict2 = {"apple","pen"};
    vector<string> dict3 = {"cats","dog","sand","and","cat"};
    vector<string> dict4 = {"cats","dog","sand","and","cat", "og"};
    vector<string> dict5 = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    cout<<sol.wordBreak("leetcode", dict1)<<"\n"; // true
    cout<<sol.wordBreak("applepenapple", dict2)<<"\n"; // true
    cout<<sol.wordBreak("catsandog", dict3)<<"\n"; // false
    cout<<sol.wordBreak("catsandog", dict4)<<"\n"; // true
    cout<<sol.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", dict5)<<"\n"; // false
}