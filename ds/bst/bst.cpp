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

void BinaryTree::Node::traverse() {

    // left

    if (left != nullptr)
      left->traverse();

    // center
    cout << data;


    // right
    if (right != nullptr)
      right->traverse();
}
void BinaryTree::Node::insert(int input) {
  if (input <= data) {
    if (left == nullptr) {
      Node *node = new Node(input);
      left = node;
    }
    else {
      left->insert(input);
    }
  }
  else {
    if (right == nullptr) {
      Node *node = new Node(input);
      right = node;
    }
    else {
      right->insert(input);
    }
  }
}

void BinaryTree::Node::find(int input) {
  if (input == data) {
    cout << "Found!" << endl;
  }
  else if (input < data) {
    if (left == nullptr) {
      cout << "Not found." << endl;
      return;
    }
    left->find(input);
  }
  else {
    if (right == nullptr) {
      cout << "Not found." << endl;
      return;
    }
    right->find(input);
  }
}

BinaryTree::BinaryTree() {
  root = nullptr;
}

void BinaryTree::insert(int data) {
  Node *node = new Node(data);
  if (root == nullptr) {
    root = node;
  }
  else {
    root->insert(data);
  }
}

void BinaryTree::traverse() {
  root->traverse();
  cout << endl;
}

void BinaryTree::find(int data) {
  root->find(data);
}

int main() {
  BinaryTree b1;
  b1.insert(9);
  b1.insert(2);
  b1.insert(4);
  b1.insert(3);
  b1.insert(8);
  b1.insert(5);
  b1.insert(7);
  b1.find(4);
  b1.find(2);
  b1.find(3);
  b1.find(1);
  b1.traverse();
}
