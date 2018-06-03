#include "stack.hpp"
#include <iostream>

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
  return 0;
}
