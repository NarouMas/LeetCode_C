#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        foo(0, n, 0, "");
        return res;
    }
    void foo(int depth, int n, int num, string s)
    {
        if(s.length() == n << 1)
        {
            res.push_back(s);
            return;
        }
        if(num < n)
            foo(depth + 1, n, num + 1, s + "(");
        if(num << 1 > s.length())
            foo(depth + 1, n, num, s + ")");
    }
};

int main()
{
    Solution sol;
    vector<string> res = sol.generateParenthesis(4);
    for(int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<"\n";
    }
}