#include <iostream>

using namespace std;

template <typename T>
T midpoint (T a, T b) {
  return (a + b)/2;
}

int main() {
  cout << midpoint('a', 'c') << endl;
  cout << midpoint(10, 20) << endl;
  return 0;
}
