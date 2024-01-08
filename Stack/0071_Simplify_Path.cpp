#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss;
        vector<string> names;
        string token, res = "";
        stack<string> st;
        ss << path;
        while(getline(ss, token, '/'))
            names.push_back(token);
        for(auto s: names)
        {
            if(s.size() == 0 || s == ".")
                continue;
            if(s == ".." && st.size() > 0)
                st.pop();
            if(s != "..")
                st.push(s);
        }
        while(!st.empty())
        {
            token = st.top();
            st.pop();
            res = "/" + token + res;
        }
        return (res.size() == 0)? "/": res;
    }
};

int main()
{
    string s1 = "/a//b/c/.././e/";
    Solution sol;

    cout<<sol.simplifyPath(s1)<<"\n";
}