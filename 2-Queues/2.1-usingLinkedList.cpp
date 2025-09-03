#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
  T val;
  Node<T>* next;
  Node(T d) {
      val = d;
      next = nullptr;
  }
};

template <typename T>
class Queue{
  Node<T>* head;
  Node<T>* tail;
  int size;

public:
  Queue() {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  void push(T val) {
    Node<T>* newNode = new Node<T>(val);
    size++;
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
  }

  T pop() {
    if (isEmpty()) throw runtime_error("Stack Underflow");

    Node<T>* curr = head;
    T poppedElement = curr->val;
    head = head->next;
    size--;
    delete curr;

    return poppedElement;
  }

  T peek() {
    if (isEmpty()) throw runtime_error("Stack is empty");
    return head->val;
  }

  bool isEmpty() {
    return head == nullptr;
  }

  int getSize() {
    return size;
  }

  ~Queue(){
    while(!isEmpty()) {
        pop();
    }
  }
};

int main() {
  Queue<int> q;

  q.push(10);
  q.push(20);
  q.push(30);

  cout << "Front element : " << q.peek() << endl;
  cout << "Popped element : " << q.pop() << endl;

  cout << "Size after pop: " << q.getSize() << endl;

  q.push(40);
  q.push(50);

  while(!q.isEmpty()) {
      cout << "Front element: "<< q.pop() << endl;
  }
}
