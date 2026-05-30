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

//main function for options
int main {
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
    else if (choice == 5) //haven't done this section yet
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
}
