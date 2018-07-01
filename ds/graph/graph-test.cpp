#include "graph.hpp"
#include <iostream>

using namespace std;

int main() {
  graph g1;
  g1.addEdge(5,10);

  g1.addEdge(10, 1);
  g1.addEdge(10, 3);
  g1.addEdge(10, 14);

  g1.addEdge(3, 19);
  g1.addEdge(19, 17);

  g1.addEdge(1, 15);
  g1.addEdge(15, 8);
  g1.addEdge(8, 2);

  g1.addEdge(14, 4);
  g1.addEdge(4, 7);

  cout << endl << endl;

  g1.searchBFS(5, 2);
  g1.searchBFS(2, 5);

  cout << endl << endl;

  g1.searchDFS(5, 2);
  g1.searchDFS(2, 5);

  cout << endl << endl;

  g1.searchBFS(3, 2);
  
  return 0;
}
