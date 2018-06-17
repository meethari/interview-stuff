#include "ll.hpp"

int main() {
  LinkedList<int> ll;
  ll.append(1);
  ll.append(2);
  ll.append(3);
  ll.prepend(4);
  ll.print();
  // whoops, shoulda put the four at the end
  // no worries, we can fix that
  ll.remove(4);
  ll.print();
  ll.append(4);
  ll.print();
  // whew, finally.
  return 0;
}
