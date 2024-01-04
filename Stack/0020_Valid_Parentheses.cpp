#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s)
        {
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else
            {
                if(st.size() == 0)
                    return false;
                char t = st.top();
                st.pop();
                if(t == '(' && c != ')')
                    return false;
                if(t == '[' && c != ']')
                    return false;
                if(t == '{' && c != '}')
                    return false;
            }
        }
        return st.size() == 0;
    }
};