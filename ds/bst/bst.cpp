#include "bst.hpp"

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
