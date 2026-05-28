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

//adding vertex
void addVertex(Graph &g, char label[])
{
  if (g.vertexCount >= max)
  {
    cout << "Graph is full" << endl;
    return;
  }
  if (getIndex(g, label) != -1)
  {
    cout << "Vertex already exists. Can't add :(" << endl;
    return;
  }
  strcpy(g.vertices[g.vertexCount], label);
  g.vertexCount++;
  cout << "Vertex is added" << endl;
}

//adding edge
void addEdge(Graph &g, char from[], char to[], int weight)
{
  int a = getIndex(g, from);
  int b = getIndex(g, to);
  if (a == -1 || b == -1)
  {
    cout << "This is invalid vertex" << endl;
    return;
  }
  g.adjacency[a][b] = weight;
  cout << "Edge added" << endl;
}

//removing edge
void removeEdge(Graph &g, char from[], char to[])
{
  int a = getIndex(g, from);
  int b = getIndex(g, to);
  if (a == -1 || b == -1)
  {
    cout << "This is invalid vertex" << endl;
    return;
  }
  g.adjacency[a][b] = 0;
  cout << "Edge removed" << endl;
}

int main {
  Graph g;
  initGraph(g);
  int choice = 1;
  char v1[label_size], v2[label_size];
  int weight;
  return 0;
  cout << "1. add edge";
  cout << "2. add vertex";
  cout << "3. remove edge";
  cout << "4. remove vertex";
  cout << "5. find shortest path";
  cout << "6. QUIT";
}
