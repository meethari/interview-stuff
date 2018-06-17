#include "bst.hpp"

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
