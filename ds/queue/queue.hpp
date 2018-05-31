class queue {

private:

  class node {
  public:
    int data;
    node *next;
    node(int input);
  };

  node *head;
  node *tail;


public:

  int isEmpty();
  int peek();
  void push(int data);
  int pop();

  queue();

};
