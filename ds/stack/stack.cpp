#include "stack.hpp"
#include <iostream>

template <typename T>
stack<T>::stack() {
  head = nullptr;
  tail = nullptr;
}

template <typename T>
int stack<T>::isEmpty() {
  return head == nullptr;
}

template <typename T>
T stack<T>::peek() {
  return head->data;
}

template <typename T>
void stack<T>::push(T data) {
  Node *node1;
  node1 = new Node;
  node1->data = data;
  node1->next = head;
  head = node1;
}

template <typename T>
T stack<T>::pop() {
  Node *copy;
  copy = head;
  head = head->next;
  T data = copy->data;
  delete copy;
  return data;
}

template class stack<int>;
