#include <iostream>
#include "queue.hpp"

using namespace std;

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

template class queue<int>;
