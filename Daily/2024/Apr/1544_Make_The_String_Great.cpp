#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string res = "";
        st.push(s[0]);
        for(int i = 1; i < s.size(); i++)
        {
            if(!st.empty() && ((s[i] == st.top() - ' ') || (s[i] == st.top() + ' ')))
                st.pop();
            else
                st.push(s[i]);
        }
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};