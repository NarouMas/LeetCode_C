#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string str: words)
        {
            bool same = true;
            for(int i = 0, j = str.size() - 1; i < j; i++, j--)
            {
                if(str[i] != str[j])
                {
                    same = false;
                    continue;
                }
            }
            if(same)
                return str;
        }
        return "";
    }
};