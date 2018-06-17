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
