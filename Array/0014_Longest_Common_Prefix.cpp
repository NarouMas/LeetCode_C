#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int index = 0;
        while(true)
        {
            char cur = ' ';
            for(int i = 0; i < strs.size(); i++)
            {
                if(index >= strs[i].size())
                    return strs[0].substr(0, index);
                else if(cur == ' ')
                    cur = strs[i][index];
                else if(cur != strs[i][index])
                    return strs[0].substr(0, index);
            }
            index++;
        }
        return "";
    }
};