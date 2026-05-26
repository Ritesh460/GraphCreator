#include <iostream>
#include <cstring>
#include <iomanip>
#include <climits>
using namespace std;
//variables for functions
const int max = 20;
const int label_size = 20;
//graph struct
struct Graph {
  char vertices[max][label_size];
  int adjacency[max][max];
  int vertexCount;
}
//initializes graph
void initGraph(Graph &g) {
  g.vertexCount = 0;
  for (int i = 0; i < max; i++)
    for (int j = 0; j < max; j++)
      g.adjacency[i][j] = 0;
}
//used for finding index of vertex
int getIndex(Graph &g, char label[]) {
  for (int i = 0; i < g.vertexCount; i++) {
    if (strcmp(g.vertices[i], label) == 0) {
      return i;
    }
  }
  return -1;
}

int main {
  Graph g;
  initGraph(g);
  int choice = 1;
  char v1[label_size], v2[label_size];
  int weight;
  return 0;
}
