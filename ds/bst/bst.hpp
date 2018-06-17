#include <iostream>

using namespace std;

/* Implementation of a Binary Tree from HackerRank's YT video

*/

class BinaryTree {
private:
  class Node {
  public:
    int data;
    Node *left, *right;
    Node(int input) {
      left = nullptr;
      right = nullptr;
      data = input;
    }

    void insert(int input);
    void find(int input);
    void traverse();

  };
  Node *root;

public:
  BinaryTree();
  void insert(int data);
  void find(int data);
  void traverse();
};
