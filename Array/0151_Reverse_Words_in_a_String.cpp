#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int index, count = 0;
        for(index = s.size() - 1; index >= 0 && s[index] == ' '; index--);
        for(; index >= 0; index--)
        {
            if(s[index] != ' ')
                count++;
            else if(count > 0)
            {
                res += s.substr(index + 1, count) + " ";
                count = 0;
            }
        }
        
        if(count > 0)
            res += s.substr(0, count) + " ";
        res.pop_back();
        return res;
    }
};

int main()
{
    string s1 = "the sky is blue";
    string s2 = "  hello world  ";
    string s3 = "a good   example";
    Solution sol;

    cout<<sol.reverseWords(s1)<<"\n";
    cout<<sol.reverseWords(s2)<<"\n";
    cout<<sol.reverseWords(s3)<<"\n";
}