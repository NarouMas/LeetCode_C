#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int a, b;
                b = st.top(); st.pop();
                a = st.top(); st.pop();
                if(tokens[i] == "+")
                    a = a + b;
                else if(tokens[i] == "-")
                    a = a - b;
                else if(tokens[i] == "*")
                    a = a * b;
                else if(tokens[i] == "/")
                    a = a / b;
                st.push(a);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};