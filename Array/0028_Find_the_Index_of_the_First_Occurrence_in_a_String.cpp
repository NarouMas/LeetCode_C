#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.size();)
        {
            int j = 0;
            bool same = true;
            for(; j < needle.size(); j++)
            {
                if(i + j >= haystack.size())
                    return -1;
                if(needle[j] != haystack[i + j])
                {
                    same = false;
                    break;
                }
            }
            if(same)
                return i;
            i += 1;
        }
        return -1;
    }
};

int main()
{
    string s1 = "sadbutsad", s1n = "sad";
    string s2 = "leetcode", s2n = "leeto";
    Solution sol;

    cout<<sol.strStr(s1, s1n) << "\n";
    cout<<sol.strStr(s2, s2n) << "\n";
}