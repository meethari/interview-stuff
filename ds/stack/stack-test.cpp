#include <iostream>
#include "stack.hpp"

using namespace std;

int main() {
  stack<int> s1;

  if (s1.isEmpty()) {
    cout << "stack is indeed empty" << endl;
  }

  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(5);

  cout << "At the top:" << s1.peek() << endl;

  cout << "Pop #1:" << s1.pop() << endl;
  cout << "Pop #2:" << s1.pop() << endl;
  cout << "Pop #3:" << s1.pop() << endl;

  s1.push(4);

  cout << "At the top:" << s1.peek() << endl;

  cout << "Pop #4:" << s1.pop() << endl;
  cout << "Pop #5:" << s1.pop() << endl;

  return 0;
}
