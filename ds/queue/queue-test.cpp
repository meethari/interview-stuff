#include <iostream>
#include "queue.hpp"

using namespace std;

int main() {
  queue<int> q1;

  if (q1.isEmpty()) {
    cout << "Queue is indeed empty" << endl;
  }

  q1.push(1);
  q1.push(2);
  q1.push(3);
  q1.push(5);

  cout << "At the top:" << q1.peek() << endl;

  cout << "Pop #1:" << q1.pop() << endl;
  cout << "Pop #2:" << q1.pop() << endl;
  cout << "Pop #3:" << q1.pop() << endl;

  q1.push(4);

  cout << "At the top:" << q1.peek() << endl;

  cout << "Pop #4:" << q1.pop() << endl;
  cout << "Pop #5:" << q1.pop() << endl;

  return 0;
}
