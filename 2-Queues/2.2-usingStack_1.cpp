#include <iostream>
#include <stack>
using namespace std;

class Queue{
  stack<int> st1;
  stack<int> st2;
public:
  Queue(){}

  // O(2n)
  void push(int val) {
    // s1 --> s2
    while(!st1.empty()){
      int topEle = st1.top();
      st1.pop();
      st2.push(topEle);
    }

    // x-> s1
    st1.push(val);

    // s2 -> s1
    while(!st2.empty()){
      int topEle = st2.top();
      st2.pop();
      st1.push(topEle);
    }
  }

  int peek() {
    return st1.top();
  }

  int pop() {
    int front_element =  st1.top();
    st1.pop();
    return front_element;
  }

  bool isEmpty() {
    return st1.empty();
  }

  int size() {
    return st1.size();
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
