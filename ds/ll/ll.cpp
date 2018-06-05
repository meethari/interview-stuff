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
  // solely for debugging purposes
  void print ();
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
    return;
  }

  Node *current;
  current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  current->next = node;

}

template <typename T>
void LinkedList<T>::remove(T data) {
  if (head == nullptr) {
    cout << "Nuffin in this list" << endl;
    return;
  }

  // special case, if the item to be deleted is head
  if (head->data == data) {
    Node *toBeDeleted = head;
    head = head->next;
    delete toBeDeleted;
    return;
  }

  Node *current = head;
  while (current->next != nullptr) {
    if (current->next->data == data) {
      Node *toBeDeleted = current->next;
      current->next = current->next->next;
      cout<<"Deleted"<<endl;
      delete toBeDeleted;
      return;
    }
    current = current->next;
  }
  // if we get to this point, that implies the item we wanted to find doesn't
  // exist. So we print an error message.
  cout<< "No matching element exists to delete" << endl ;

}

template <typename T>
void LinkedList<T>::print() {
  // empty case
  if (head == nullptr) {
    cout << "Empty" << endl;
    return;
  }
  Node *current = head;
  do {

    cout<<current->data<<" ";
    current = current->next;
  } while (current != nullptr);
  cout << endl;
}

int main() {
  LinkedList<int> ll;
  ll.append(1);
  ll.append(2);
  ll.append(3);
  ll.prepend(4);
  ll.print();
  // whoops, shoulda put the four at the end
  // no worries, we can fix that
  ll.remove(4);
  ll.print();
  ll.append(4);
  ll.print();
  // whew, finally.
  return 0;
}
