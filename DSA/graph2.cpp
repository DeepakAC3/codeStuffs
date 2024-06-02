#include <iostream>
#include <stack>
#include <vector>
//rewrite the codes using arrays instead of vectors

using namespace std;

// Graph class
class Graph {
public:
    Graph(int V) : V(V), adj(V) {}

    // Add edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Depth-first search using a stack
    void DFS(int s) {
        // Create a stack for DFS
        stack<int> stack;

        // Mark all the vertices as not visited
        vector<bool> visited(V, false);

        // Push the starting vertex onto the stack
        stack.push(s);

        // Loop until the stack is empty
        while (!stack.empty()) {
            // Pop a vertex from the stack
            int u = stack.top();
            stack.pop();

            // If the vertex has not been visited yet
            if (!visited[u]) {
                // Mark it as visited and print it
                visited[u] = true;
                cout << u << " ";

                // Push all the adjacent vertices onto the stack
                for (int v : adj[u]) {
                    stack.push(v);
                }
            }
        }
    }

private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
};

// Driver code
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "DFS starting from vertex 2: ";
    g.DFS(2);
    cout << endl;

    return 0;
}
