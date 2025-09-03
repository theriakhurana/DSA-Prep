#include <iostream>
using namespace std;
class Node{
public:
  int val;
  Node* next;
  Node(int d) {
      val = d;
      next = nullptr;
  }
};

class Stack{
  Node* head;
  int size;
public:
  Stack() {
    size = 0;
    head = nullptr;
  }

  void push(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    size++;
  }

  int pop() {
    if (isEmpty()) throw runtime_error("Stack Underflow");

    Node* curr = head;
    int element = curr->val;
    head = head->next;
    delete curr;
    size--;
    return element;
  }

  int peek() {
    if (isEmpty()) throw runtime_error("Stack is empty");

    return head->val;
  }

  bool isEmpty() {
    return head == nullptr;
  }

  int getSize() {
    return size;
  }

  ~Stack() {
    while(!isEmpty()) {
        pop();
    }
  }
};

int main() {
  Stack st;
  st.push(1);
  st.push(2);
  st.push(3);

  cout << "Top element: "  << st.peek() << endl;
  cout << "Size: " << st.getSize() << endl;

  cout << "Popped element: " << st.pop() << endl;
  cout << "Size after pop: " << st.getSize() << endl;

  st.push(4);
  st.push(5);
  st.push(6);

  while(!st.isEmpty()) {
      cout << "Popped element: "  << st.pop() << endl;
  }
}
