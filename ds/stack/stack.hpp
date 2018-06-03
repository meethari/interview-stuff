template <typename T>
class Stack {
private:
  class Node {
    T data;
    Node *next;
    // next points downards, i.e from head to tail
  };

  Node *head, *tail;

public:
  void push(T data);
  T pop();
  T peek();
  int isEmpty();
};
