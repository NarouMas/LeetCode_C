#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        string digit[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
        if(digits.length() == 0)
            return res;
        foo(digits, digit, 0, "");
        return res;
    }
    void foo(string digits, string *digit, int depth, string s)
    {
        if(depth >= digits.length())
        {
            res.push_back(s);
            return;
        }
        int num = digits[depth] - '0';
        for(int i = 0; i < digit[num].length(); i++)
        {
            s += digit[num][i];
            foo(digits, digit, depth + 1, s);
            s.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<string> res = sol.letterCombinations("2");
    for(int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<"\n";
    }
}