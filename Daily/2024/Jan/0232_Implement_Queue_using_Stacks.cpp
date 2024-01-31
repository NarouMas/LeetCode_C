#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> temp;
        int n;
        while(!st.empty())
        {
            n = st.top(); st.pop();
            temp.push(n);
        }
        st.push(x);
        while(!temp.empty())
        {
            n = temp.top(); temp.pop();
            st.push(n);
        }
    }
    
    int pop() {
        int n = st.top();
        st.pop();
        return n;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */