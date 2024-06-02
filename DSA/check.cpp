#include<iostream>
using namespace std;
class Graph {
int V; // Number of vertices 
int** adj; // Adjacency list
public:
Graph(int V): V(V) {
     adj = new int*[V]; 
     for (int i = 0; i < V; i++) { 
        adj[i]= new int[V]; 
        for (int j=0; j < V; j++) { 
            adj[i][j] = 0;
        }
    }
}
// Add an edge to the graph 
void addEdge(int u, int v) { 
    adj[u][v] = 1;
}
// Depth First Search 
void DFS(int startNode) { 
    bool* visited = new bool[V]; 
    for (int i = 0; i < V; i++){ 
        visited[i] = false;
        }
DFSUtil(startNode, visited);
cout << endl;
delete[] visited;
}
void DFSUtil(int v, bool visited[]) { 
    cout << v << " "; 
    visited[v] =true;
    for (int neighbor = 0; neighbor < V; neighbor++) { 
        if (adj[v][neighbor] && !visited [neighbor]) {
             DFSUtil(neighbor, visited);
        }
    }
}
};

int main() {
int V, E; 
cin >> V; 
cin >> E;
Graph graph(V);
for (int i = 0; i < E; i++) { 
    int u, v; 
    cin >> u >> v; 
    graph.addEdge(u, v);
}
int startNode; 
cin >> startNode;
graph.DFS(startNode);
return 0;
}

