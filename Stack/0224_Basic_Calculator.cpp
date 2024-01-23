#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<string> tokens = s2tokens(s);
        vector<string> post = infix2post(tokens);
        
        return evalPost(post);
    }
private:
    vector<string> s2tokens(string s)
    {
        vector<string> res;
        string space_s = "", token;
        stringstream ss;
        bool should_be_num = true;
        space_s += s[0];
        for(int i = 1; i < s.size(); i++)
        {
            if(isDigit(s[i]) && !isDigit(s[i - 1]))
                space_s += ' ';
            else if(isOper(s[i]) && !isOper(s[i - 1]))
                space_s += ' ';
            else if(isOper(s[i]) && isOper(s[i - 1]))
                space_s += ' ';
            space_s += s[i];
        }
        //cout<<space_s<<"\n";
        ss<<space_s;
        while(ss>>token)
        {
            if(should_be_num && token == "-")
                res.push_back("0");
            res.push_back(token);
            if(isDigit(token[0]) || token[0] == ')')
                should_be_num = false;
            else
                should_be_num = true;  
        }
        return res;
    }
    vector<string> infix2post(vector<string> tokens)
    {
        vector<string> post;
        stack<string> st;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(isDigit(tokens[i][0]))
            {
                post.push_back(tokens[i]);
                continue;
            }
            else if(tokens[i][0] == '(')
            {
                st.push("(");
                continue;
            }
            else if(tokens[i][0] == ')')
            {
                while (st.top() != "(")
                {
                    post.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(!st.empty() && st.top() != "(")
                {
                    post.push_back(st.top());
                    st.pop();
                }
                st.push(tokens[i]);
            }
        }
        while(!st.empty())
        {
            post.push_back(st.top());
            st.pop();
        }
        // for(int i = 0; i < post.size(); i++)
        //     cout<<"post:"<<post[i]<<"\n";
        return post;
    }
    int evalPost(vector<string> post)
    {
        stack<int> st;
        int n1, n2;
        for(int i = 0; i < post.size(); i++)
        {
            if(isDigit(post[i][0]))
                st.push(stoi(post[i]));
            else
            {
                n2 = st.top(); st.pop();
                n1 = st.top(); st.pop();
                if(post[i] == "+")
                {
                    n1 += n2;
                    st.push(n1);
                }
                else
                {
                    n1 -= n2;
                    st.push(n1);
                }
            }
        }
        return st.top();
    }
    bool isDigit(char c)
    {
        if(c >= '0' && c <= '9')
            return true;
        return false;
    }
    bool isOper(char c)
    {
        if(c == '+' || c == '-' || c == '(' || c == ')')
            return true;
        return false;
    }
};

int main()
{
    string s1 = "1 + 1";
    string s2 = " 2-1 + 2 ";
    string s3 = "(1+(4+5+2)-3)+(6+8)";
    string s4 = "3-(-4)";
    Solution sol;

    cout<<sol.calculate(s1)<<"\n";
    cout<<sol.calculate(s2)<<"\n";
    cout<<sol.calculate(s3)<<"\n";
    cout<<sol.calculate(s4)<<"\n";
}