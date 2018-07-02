#include <queue>
#include <stack>
#include <iostream>
#include <set>
#include "graph.hpp"

#define INT_MAX_HARI (unsigned int) -1

using namespace std;

graph::graph() {
  for (int i = 0; i < NODE_COUNT; i++) {
    for (int j = 0; j < NODE_COUNT; j++) {
      matrix[i][j] = INT_MAX_HARI;
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


void graph::addEdge(int source, int destination, int weight) {
  if (matrix[source][destination] != INT_MAX_HARI) {
    cout << "Edge (" << source << ", " << destination <<") already exists." << endl;
  }
  else {
    matrix[source][destination] = (unsigned int) weight;
    cout << "Edge (" << source << ", " << destination <<") added with weight " << weight << endl;
  }
}

void graph::searchBFS(int source, int destination) {
  // Random code to debug stuff
  /*
  for (int i = 0; i < NODE_COUNT; i++) {
    for (int j = 0; j < NODE_COUNT; j++)
      cout<<matrix[i][j]<<" ";
    cout<<endl;
  }
  */
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
      if (matrix[currentSourceNode][j] != INT_MAX_HARI) {
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
      if (matrix[currentSourceNode][j] != INT_MAX_HARI) {
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

void graph::searchDijkstra(int source, int destination) {
  // I'm gonna use the six steps outlined in the wiki article

  // Step 1: create a set called unvisited and put all nodes in it
  set<int> unvisited;

  for (int i = 0; i < NODE_COUNT; i++)
    unvisited.insert(i);

  // Step 2: Mark the current node (source) as zero distance and the
  // rest as infinite distance
  unsigned int tentative_distances[NODE_COUNT];

  for (int i = 0; i < NODE_COUNT; i++) {
    tentative_distances[i] = INT_MAX_HARI;
  }
  tentative_distances[source] = 0;

  int current_node = source;

  // int unreachable_flag = 0

  int parent[NODE_COUNT];
  for (int i = 0; i < NODE_COUNT; i++) {
    parent[i] = -1;
  }

  do {
    unsigned int current_node_distance = tentative_distances[current_node];
    cout << "Current Node: " << current_node << ", Cost: ";
    cout << current_node_distance << endl;
    // Step 3: Find the (minimum) tentative distances of all your neighbours

    for (int i = 0; i < NODE_COUNT; i++) {
      if (matrix[current_node][i] != INT_MAX_HARI) {
        // identified a neighbour

        // calculating new tentative distance
        unsigned int new_distance = current_node_distance + matrix[current_node][i];

        // if the new tentative distance is older than the previous one, replace it
        if (tentative_distances[i] > new_distance) {
          tentative_distances[i] = new_distance;
          // came up with this on my own
          // don't understand completely
          parent[i] = current_node;
        }
      }
    }

    // Step 4: Once done iterating over neighbours, mark current_node as visited
    // In other words, remove it from the unvisited set.

    unvisited.erase(current_node);

    // Step 5: If we have reached the destination, we are done. Quit the algo.
    // Else, if the minimum tentative distance among the unvisited members is
    // INT_MAX_HARI, then there exists no path. Quit the algorithm.
    // additionally, we'll also try to find the node which has the minimum
    // tentative distance to be made current_node in the next iteration

    if (current_node == destination) {
      cout << "Shortest Path Found! The cost is " << current_node_distance;
      cout << endl;
      /*
      for (int  i = 0; i < NODE_COUNT; i ++) {

        cout << "Node: " << i << " Tentative Distance: ";
        cout << tentative_distances[i] << endl;
      }
      */

      // my own code
      cout << "Calculating path." << endl;

      stack<int> s1;
      for (current_node = destination; current_node != source; current_node = parent[current_node])
        s1.push(current_node);
      s1.push(source);

      cout << "Printing path:" << endl;

      while (s1.size() != 0) {
        cout << s1.top() << " ";
        s1.pop();
      }

      cout << endl;

      return;
    }

    unsigned int minimum_unvisited_distance = INT_MAX_HARI;
    int minimum_indice = 0;

    for (int i = 0; i < NODE_COUNT; i++) {
      // First, check if node i belongs to unvisited
      set<int>::iterator iter;
      iter = unvisited.find(i);
      if (*iter == i) {
        // Node i indeed belongs to unvisited
        if (tentative_distances[i] <= minimum_unvisited_distance) {
          minimum_unvisited_distance = tentative_distances[i];
          minimum_indice = i;
        }
      }
    }

    if (minimum_unvisited_distance == INT_MAX_HARI) {
      cout << "Sorry, there exists no path between " << source;
      cout << " and " << destination << endl;
      return;
    }

    // Step 6: If none of the above conditions apply, repeat this process
    // with the node with minimum tentative distance as the current node

    current_node = minimum_indice;

  } while (1 /*unreachable_flag != 1*/);
}
