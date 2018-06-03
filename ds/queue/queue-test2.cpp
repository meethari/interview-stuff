#include <iostream>

template <typename T>
class queue{

private:

  class node {
  public:
    T data;
    node *next;
    node(T input);
  };

  node *head;
  node *tail;


public:

  T isEmpty();
  T peek();
  void push(T data);
  T pop();

  queue();

};

template <typename T>
queue<T>::node::node(T input) {
  data = input;
  next = nullptr;
}

template <typename T>
queue<T>::queue() {
  head = tail = nullptr;
}

template <typename T>
T queue<T>::isEmpty() {
  return head==nullptr;
}

template <typename T>
T queue<T>::peek() {
  return head->data;
}

template <typename T>
void queue<T>::push(T data) {
  node *node1;
  node1 = new node(data);
  if (isEmpty()) {
    head = tail = node1;
  } else {
    tail->next = node1;
    tail = node1;
  }
  node1->next = nullptr;

}

template <typename T>
T queue<T>::pop() {
  T val = head->data;
  delete head;
  head = head->next;
  // if queue becomes empty case
  if (isEmpty()) {
    tail = nullptr;
  }
  return val;
}

using namespace std;

int main() {
  queue<char> q1;

  if (q1.isEmpty()) {
    cout << "Queue is indeed empty" << endl;
  }

  q1.push('1');
  q1.push('a');
  q1.push('n');
  q1.push('g');

  cout << "At the top:" << q1.peek() << endl;

  cout << "Pop #1:" << q1.pop() << endl;
  cout << "Pop #2:" << q1.pop() << endl;
  cout << "Pop #3:" << q1.pop() << endl;

  q1.push('i');

  cout << "At the top:" << q1.peek() << endl;

  cout << "Pop #4:" << q1.pop() << endl;
  cout << "Pop #5:" << q1.pop() << endl;

  return 0;
}
