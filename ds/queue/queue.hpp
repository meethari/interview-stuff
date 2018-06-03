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
