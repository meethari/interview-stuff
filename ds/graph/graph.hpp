// no templating, since the nodes don't contain any data!

#define NODE_COUNT 20

class graph {
private:
  unsigned int matrix[NODE_COUNT][NODE_COUNT];
public:
  graph();
  void addEdge(int source, int destination,int weight);
  void deleteEdge(int source, int destination);
  void searchBFS(int source, int destination);
  void searchDFS(int source, int destination);
  void searchDijkstra(int source, int destination);
};
