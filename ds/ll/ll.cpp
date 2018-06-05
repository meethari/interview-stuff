#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
  class Node {
  public:
    Node *next;
    T data;
    Node(T input);
  };

  Node *head;

public:
  // constructor
  LinkedList();
  void append (T data);
  void prepend (T data);
  // because delete is a protected keyword
  void remove (T data);
};

template <typename T>
LinkedList<T>::Node::Node(T input) {
  next = nullptr;
  data = input;
}

template <typename T>
LinkedList<T>::LinkedList() {
  head = nullptr;
}

template <typename T>
void LinkedList<T>::prepend(T data) {
  Node *node = new Node(data);
  node->next = head;
  head = node;

}

template <typename T>
void LinkedList<T>::append(T data) {
  Node *node = new Node(data);
  if (head == nullptr) {
    head = node;
  }
  else {
    Node *current;
    current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = node;
  }
}

template <typename T>
void LinkedList<T>::remove(T data) {
  if (head == nullptr) {
    // empty list, so do nothing
    return;
  }
  else {
    // special case, if the item to be deleted is head
    if (head->data == data) {
      Node *toBeDeleted = head;
      head = head->next;
      delete head;
      return;
    }

    Node *current = head;
    while (current->next != nullptr) {
      if (current->next->data == data) {
        Node *toBeDeleted = current->next;
        current->next = current->next->next;
        delete toBeDeleted;
      }
      current = current->next;
    // if we get to this point, that implies the item we wanted to find doesn't
    // exist. So we print an error message.
    cout<< "No matching element exists to delete\n" ;
    }

  }
}

int main() {
  LinkedList<int> ll;
  ll.append(5);
  ll.prepend(6);
  ll.prepend(7);
  ll.remove(6);
  ll.remove(42);
  return 0;
}
