#include <iostream>

using namespace std;

template <typename T>
class Stack {


public:
  class Node {
  public:
    T data;
    Node *next;
    // next points downards, i.e from head to tail
  };
  void push(T data);
  T pop();
  T peek();
  int isEmpty();

private:

  Node *head, *tail;
};

template <typename T>
int Stack<T>::isEmpty() {
  return head == nullptr;
}

template <typename T>
T Stack<T>::peek() {
  return head->data;
}

template <typename T>
void Stack<T>::push(T data) {
  Node *node1;
  node1 = new Node;
  node1->data = data;
  node1->next = head;
  head = node1;
}

template <typename T>
T Stack<T>::pop() {
  Node *copy;
  copy = head;
  head = head->next;
  T data = copy->data;
  delete copy;
  return data;
}

int main() {
  Stack<int> s1;

  if (s1.isEmpty()) {
    cout << "Stack is indeed empty" << endl;
  }

  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(5);

  cout << "At the top:" << s1.peek() << endl;

  cout << "Pop #1:" << s1.pop() << endl;
  cout << "Pop #2:" << s1.pop() << endl;
  cout << "Pop #3:" << s1.pop() << endl;

  s1.push(4);

  cout << "At the top:" << s1.peek() << endl;

  cout << "Pop #4:" << s1.pop() << endl;
  cout << "Pop #5:" << s1.pop() << endl;

  return 0;
}
