#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> st;
    int m = INT32_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push({val, m});
        m = min(m, val);
    }
    
    void pop() {
        int a = st.top().first;
        if(a == m)
            m = st.top().second;
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */