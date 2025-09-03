#include <iostream>
#include <queue>
using namespace std;

class Stack{
  queue<int> q;
public:
  Stack(){}

  void push(int val) {
    int size = q.size();
    q.push(val);

    // make the current one be at the front
    for(int i = 1; i <= size; i++) {
        q.push(q.front());
        q.pop();
    }
  }

  int pop() {
    if(q.empty()) throw runtime_error("Stack underflow");
    int top_element = q.front();
    q.pop();
    return top_element;
  }

  int top() {
    return q.front();
  }

  int size() {
    return q.size();
  }

  bool isEmpty() {
    return q.empty();
  }
};


int main() {
  Stack st;
  st.push(1);
  st.push(2);
  st.push(3);

  cout << "Top element: "  << st.top() << endl;
  cout << "Size: " << st.size() << endl;

  cout << "Popped element: " << st.pop() << endl;
  cout << "Size after pop: " << st.size() << endl;

  st.push(4);
  st.push(5);
  st.push(6);

  while(!st.isEmpty()) {
      cout << "Popped element: "  << st.pop() << endl;
  }
}
