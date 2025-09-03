#include <iostream>
#include <stack>
using namespace std;

class Queue{
  stack<int> st1;
  stack<int> st2;
public:
  Queue(){}

  void push(int val) {
    st1.push(val);
  }

  // O(n)
  int peek() {
    if(!st2.empty()) {
      return st2.top();
    }

    while(!st1.empty()) {
      st2.push(st1.top());
      st1.pop();
    }
    return st2.top();
  }

  // O(n)
  int pop() {
    if(!st2.empty()) {
      int topelement = st2.top();
      st2.pop();
      return topelement;
    }

    while(!st1.empty()) {
      st2.push(st1.top());
      st1.pop();
    }

    int topelement = st2.top();
    st2.pop();
    return topelement;
  }

  bool isEmpty() {
    return st1.empty() && st2.empty();
  }

  int size() {
    return st1.size() + st2.size();
  }
};

int main() {
  Queue q;

  q.push(10);
  q.push(20);
  q.push(30);

  cout << "Front element : " << q.peek() << endl;
  cout << "Popped element : " << q.pop() << endl;

  cout << "Size after pop: " << q.size() << endl;

  q.push(40);
  q.push(50);

  while(!q.isEmpty()) {
    cout << "Front element: "<< q.pop() << endl;
  }
}
