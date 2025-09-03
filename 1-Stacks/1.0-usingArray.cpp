#include <iostream>
using namespace std;

template <typename T>
class Stack{
  int top;
  int capacity;
  T* arr;

  void resize(int newCapacity) {
    T* newArr = new T[newCapacity];
    for(int i = 0; i <= top; i++) {
      newArr[i] = arr[i];
    }

    delete [] arr;
    arr = newArr;
    capacity = newCapacity;
  }

public:
  Stack() {
    capacity = 1;
    top = -1;
    arr = new T[capacity];
  }

  void push(int val) {
    // stack full --> double the size of the array
    if (top == capacity -1) {
      resize(capacity * 2);
    }

    arr[++top] = val;
  }

  int pop() {
    if (isEmpty()) throw runtime_error("Stack underflow");

    int element = arr[top--];
    if (top > -1 && top < capacity/4) {
      resize(capacity / 2);
    }

    return element;
  }

  int peek() {
    if (isEmpty()) throw runtime_error("Stack is empty");
    return arr[top];
  }

  bool isEmpty() {
    return top == -1;
  }

  int size() {
    return top+1;
  }

  ~Stack() {
    delete [] arr;
  }
};

int main() {
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Top element: "  << st.peek() << endl;
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