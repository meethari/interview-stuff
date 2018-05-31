#include <iostream>
#include "queue.hpp"

using namespace std;

queue::node::node(int input) {
  data = input;
  next = nullptr;
}

queue::queue() {
  head = tail = nullptr;
}

int queue::isEmpty() {
  return head==nullptr;
}

int queue::peek() {
  return head->data;
}

void queue::push(int data) {
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

int queue::pop() {
  int val = head->data;
  delete head;
  head = head->next;
  // if queue becomes empty case
  if (isEmpty()) {
    tail = nullptr;
  }
  return val;
}
