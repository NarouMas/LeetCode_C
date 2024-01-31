#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        st.push(temperatures.size() - 1);
        for(int i = temperatures.size() - 2; i >= 0; i--)
        {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
            res[i] = (st.empty()) ? 0: st.top() - i;
            st.push(i);
        }
        return res;
    }
};