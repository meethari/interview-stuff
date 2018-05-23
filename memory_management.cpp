#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

int main() {

  int n;
  cout << "How many numbers would you like to enter?" << endl;
  cin >> n;

  int *arr;
  arr = new (nothrow) int[n];

  if (arr == nullptr) {
    cout << "Error allocating space" << endl;
    exit(1);
  }

  for (int i = 0; i < n; i++) {
    cout << "Enter number " << i + 1 << endl;
    // printf("Enter the %dth number\n", i+1);
    cin >> arr[i];
  }

  cout << "Printing out the entered numbers:" << endl;

  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }

  delete[] arr;

  return 0;
}
