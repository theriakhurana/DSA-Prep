#include <iostream>
using namespace std;

class Queue{
  int front;
  int rear;
  int* arr;
  int currSize;
  int capacity;

  void resize(int newCapacity) {
    int* newArr = new int[newCapacity];
    for(int i = 0; i < currSize; i++) {
        newArr[i] = arr[(front + i) % capacity];
    }
    delete [] arr;
    arr = newArr;
    capacity = newCapacity;
    front  = 0;
    rear = currSize-1;
  }

public:
  Queue() {
    capacity = 1;
    currSize = 0;
    front = rear = -1;
    arr = new int[capacity];
  }

  ~Queue() {
    delete [] arr;
  }

  void push(int val) {
    if(isFull()) resize(capacity*2);
    if(isEmpty()){
        front = rear = 0;
    } else {
        rear = (rear+1) % capacity;
    }

    arr[rear] = val;
    currSize++;
  }

  int pop() {
    if(isEmpty()) throw runtime_error("Queue underflow");
    int dequeuedValue = arr[front];
    front = (front+1) % capacity;
    currSize--;

    if(isEmpty()){
        front = rear = -1;
    }

    if (currSize > 0 && currSize < capacity / 4) {
        resize(capacity/2);
    }
    return dequeuedValue;
  }

  int peek() {
    if(isEmpty()) throw runtime_error("Queue is empty");
    return arr[front];
  }

  bool isEmpty() {
    return currSize == 0;
  }

  bool isFull() {
    return currSize == capacity;
  }

  int size() {
    return currSize;
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
