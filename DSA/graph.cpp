#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graph class
class Graph {
    int V; // number of vertices
    vector<int> *adj; // adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    // function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // add w to v's list
    }

    // BFS traversal of the vertices reachable from s
    void BFS(int s) {
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;

        // Create a queue for BFS
        queue<int> q;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        q.push(s);

        // 'i' will be used to get all adjacent vertices of a vertex
        vector<int>::iterator i;

        while(!q.empty()) {
            // Dequeue a vertex from queue and print it
            s = q.front();
            cout << s << " ";
            q.pop();

            // Get all adjacent vertices of the dequeued vertex s
            // If an adjacent vertex has not been visited, then mark it visited and enqueue it
            for(i = adj[s].begin(); i != adj[s].end(); ++i) {
                if(!visited[*i]) {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
    }
};

int main() {
    Graph g(4); // create a graph with 4 vertices

    // add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS traversal starting from vertex 2: ";
    g.BFS(2);

    return 0;
}
