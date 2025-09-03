// Leetcode 20 (Easy)

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '[' || s[i] =='{') {
        st.push(s[i]);
      } else {
        if (st.empty()) return false;
        int top_element = st.top();

        // check if this closing has a valid opening
        if((s[i] == ']' && top_element == '[') || (s[i] == ')' && top_element == '(') ||
        (s[i] == '}' && top_element == '{')) st.pop();
        else {
            return false;
        }
      }
    }
    return st.empty();
  }
};