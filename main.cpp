#include <iostream>
#include <cstring>
#include <iomanip>
#include <climits>
using namespace std;

//variables for functions
const int max_vertices = 20;
const int label_size = 20;

//graph struct
struct Graph {
  char vertices[max_vertices][label_size];
  int adjacency[max_vertices][max_vertices];
  int vertexCount;
};

//initializes graph
void initGraph(Graph &g) {
  g.vertexCount = 0;
  for (int i = 0; i < max_vertices; i++)
    for (int j = 0; j < max_vertices; j++)
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
  if (g.vertexCount >= max_vertices)
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


//removing vertex
void removeVertex(Graph &g, char label[])
{
  int index = getIndex(g, label);
  if (index == -1)
  {
    cout << "Vertex not found :(" << endl;
    return;
  }
  for (int i = index; i < g.vertexCount - 1; i++) {
    strcpy(g.vertices[i], g.vertices[i + 1]);
  }
  for (int i = index; i < g.vertexCount - 1; i++) {
    for (int j = 0; j < g.vertexCount; j++) {
      g.adjacency[i][j] = g.adjacency[i + 1][j];
    }
  }
  for (int j = index; j < g.vertexCount - 1; j++) {
    for (int i = 0; i < g.vertexCount; i++) {
      g.adjacency[i][j] = g.adjacency[i][j + 1];
    }
  }
  g.vertexCount--;
  cout << "Vertex removed" << endl;
}

//printing adjacency table
void printTable(Graph &g)
{
  cout << "\nAdjacency Table:\n\n";
  cout << setw(8) << ""; //found another command I thought I could use called setw which sets width
  for (int i = 0; i < g.vertexCount; i++) {
    cout << setw(8) << g.vertices[i];
  }
  cout << endl;
  for (int i = 0; i < g.vertexCount; i++) {
    cout << setw(8) << g.vertices[i];
    for (int j = 0; j < g.vertexCount; j++) {
      cout << setw(8) << g.adjacency[i][j];
    }
    cout << endl;
  }
}

//shortest path algorithim
void shortestPath(Graph &g, char start[], char end[])
{
  int s = getIndex(g, start);
  int e = getIndex(g, end);
  if (s == -1 || e == -1)
  {
    cout << "Invalid vertex :(" << endl;
    return;
  }
  int dist[max_vertices];
  bool visited[max_vertices];
  int prev[max_vertices];
  for (int i = 0; i < g.vertexCount; i++)
  {
    dist[i] = INT_MAX; //found this online with climits and how it gets maximum possible integer
    visited[i] = false;
    prev[i] = -1;
  }

  dist[s] = 0;
  for (int i = 0; i < g.vertexCount - 1; i++)
  {
    int u = -1;
    int minDist = INT_MAX;
    for (int j = 0; j < g.vertexCount; j++)
    {
      if (!visited[j] && dist[j] < minDist)
      {
        minDist = dist[j];
        u = j;
      }
    }
    if (u == -1) {
      break;
    }
    visited[u] = true;
    for (int v = 0; v < g.vertexCount; v++) {
      if (g.adjacency[u][v] > 0 && !visited[v] && dist[u] != INT_MAX && dist[u] + g.adjacency[u][v] < dist[v])
        {
          dist[v] = dist[u] + g.adjacency[u][v];
          prev[v] = u;
        }
    }
  }

  if (dist[e] == INT_MAX)
  {
    cout << "No path exists." << endl;
    return;
  }
  int path[max_vertices];
  int size = 0;
  for (int at = e; at != -1; at = prev[at]) {
    path[size++] = at;
  }
  cout << "\nShortest Path:" << endl;
  for (int i = size - 1; i >= 0; i--)
  {
    cout << g.vertices[path[i]];
    if (i > 0) {
      cout << " -> ";
    }
  }
  cout << "\nTotal Weight: " << dist[e] << endl;
}

//main function for options
int main() {
  Graph g;
  initGraph(g);
  int choice = 1;
  char v1[label_size], v2[label_size];
  int weight;
  while (choice != 7) {
    cout << "1. add vertex" << endl;
    cout << "2. add edge" << endl;
    cout << "3. remove vertex" << endl;
    cout << "4. remove edge" << endl;
    cout << "5. find shortest path" << endl;
    cout << "6. print table" << endl;
    cout << "7. QUIT" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    if (choice == 1)  
    {
      cout << "Vertex: ";
      cin >> v1;
      addVertex(g, v1);
    }
    else if (choice == 2)
    {
      cout << "From: ";
      cin >> v1;
      cout << "To: ";
      cin >> v2;
      cout << "Weight: ";
      cin >> weight;
      addEdge(g, v1, v2, weight);
    }
    else if (choice == 3)
    {
      cout << "Vertex: ";
      cin >> v1;
      removeVertex(g, v1);
    }
    else if (choice == 4)
    {
      cout << "From: ";
      cin >> v1;
      cout << "To: ";
      cin >> v2;
      removeEdge(g, v1, v2);
    }
    else if (choice == 5) 
    {
      cout << "Start: ";
      cin >> v1;
      cout << "End: ";
      cin >> v2;
      shortestPath(g, v1, v2);
    }
    else if (choice == 6)
    {
      printTable(g);
    }
    else if (choice == 7)
    {
      cout << "Goodbye.";
    }
    else
    {
      cout << "Invalid choice." << endl;
    }
  }
  return 0;
}
