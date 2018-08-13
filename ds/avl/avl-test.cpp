#include "avl.hpp"
#include <iostream>

using namespace std;

int main() {

    avl a1;
    a1.insert(7);
    a1.insert(6);
    a1.insert(5);
    a1.insert(4);
    a1.insert(3);
    a1.insert(2);
    a1.insert(1);
    a1.inorder_traverse();
    cout << "Tree height: " << a1.height() << endl;
    return 0;
}

