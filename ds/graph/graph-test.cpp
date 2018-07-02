#include "graph.hpp"
#include <iostream>

using namespace std;

int main() {
  graph g1;

  // source, destination, weight
  g1.addEdge(1, 2, 1);
  g1.addEdge(1, 3, 2);
  g1.addEdge(1, 4, 3);

  g1.addEdge(2, 5, 2);
  g1.addEdge(5, 8, 2);
  g1.addEdge(8, 11, 2);

  g1.addEdge(3, 6, 2);
  g1.addEdge(6, 9, 1);
  g1.addEdge(9, 11, 7);

  g1.addEdge(4, 7, 1);
  g1.addEdge(7, 10, 1);
  g1.addEdge(10, 11, 1);

  cout << endl << endl;

  // g1.searchBFS(10, 2);
  g1.searchDijkstra(1, 11);
  return 0;
}
