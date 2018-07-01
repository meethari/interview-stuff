#include <queue>
#include <stack>
#include <iostream>
#include "graph.hpp"

using namespace std;

graph::graph() {
  for (int i = 0; i < NODE_COUNT; i++) {
    for (int j = 0; j < NODE_COUNT; j++) {
      matrix[i][j] = 0;
    }
  }
}

void graph::deleteEdge(int source, int destination) {

  if (matrix[source][destination] == 0) {
    cout << "Edge (" << source << ", " << destination <<") doesn't exist." << endl;
  }
  else {
    matrix[source][destination] = 0;
    cout << "Edge (" << source << ", " << destination <<") deleted." << endl;
  }
}


void graph::addEdge(int source, int destination) {
  if (matrix[source][destination] == 1) {
    cout << "Edge (" << source << ", " << destination <<") already exists." << endl;
  }
  else {
    matrix[source][destination] = 1;
    cout << "Edge (" << source << ", " << destination <<") added." << endl;
  }
}

void graph::searchBFS(int source, int destination) {
  cout << "Beginning BFS between " << source << " and " << destination << endl;
  int visited[NODE_COUNT];
  for (int i = 0; i < NODE_COUNT; i++) {
    visited[i] = 0;
  }
  queue<int> q1;
  q1.push(source);
  while (q1.size() != 0) {
    int currentSourceNode = q1.front();
    q1.pop();
    cout << "currentNode: " << currentSourceNode << endl;
    if (currentSourceNode == destination) {
      cout << "Found a path!" << endl;
      return;
    }
    for (int j = 0; j < NODE_COUNT; j++) {
      if (matrix[currentSourceNode][j] == 1) {
        // we've found a child!
        int child = j;

        if (visited[child] == 1) {
          // we've already been here, nothing to see
          continue;
        }
        else
          visited[child] = 1;

        q1.push(child);
      }
    }
  }
  cout << "No path found" << endl;
}

void graph::searchDFS(int source, int destination) {
  cout << "Beginning DFS between " << source << " and " << destination << endl;
  int visited[NODE_COUNT];
  for (int i = 0; i < NODE_COUNT; i++) {
    visited[i] = 0;
  }
  stack<int> s1;
  s1.push(source);
  while (s1.size() != 0) {
    int currentSourceNode = s1.top();
    s1.pop();
    cout << "currentNode: " << currentSourceNode << endl;
    if (currentSourceNode == destination) {
      cout << "Found a path!" << endl;
      return;
    }
    for (int j = 0; j < NODE_COUNT; j++) {
      if (matrix[currentSourceNode][j] == 1) {
        // we've found a child!
        int child = j;

        if (visited[child] == 1) {
          // we've already been here, nothing to see
          continue;
        }
        else
          visited[child] = 1;

        s1.push(child);
      }
    }
  }
  cout << "No path found" << endl;
}
