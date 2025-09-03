// Leetcode 155 (Medium)

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long minValue;
    
    MinStack() {
        minValue = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minValue = val;
        }
        else {
            if (val > minValue) st.push(val);
            else {
                st.push((2LL * val - minValue));
                minValue = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long element = st.top();
        st.pop();

        if(element < minValue) {
            minValue = (2 * minValue) - element;
        }
    }
    
    int top() {
        return (st.top() < minValue) ? (int) minValue : (int) st.top();
    }
    
    int getMin() {
        return (int) minValue;
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