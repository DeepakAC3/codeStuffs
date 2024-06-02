    #include <iostream>
    #include <vector>
    #include <queue>
    #include <climits>

    using namespace std;

    // Structure to represent a node in the graph
    struct Node {
        int id;
        int weight;
    };

    // Function to perform Dijkstra's algorithm
    void dijkstra(vector<vector<Node>>& graph, int start) {
        int n = graph.size();
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) {
                continue;
            }

            visited[u] = true;

            for (const auto& neighbor : graph[u]) {
                int v = neighbor.id;
                int weight = neighbor.weight;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print the shortest distances from the start node
        cout << "Shortest distances from node " << start << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    int main() {
        // Create a graph
        int n = 5; // Number of nodes
        vector<vector<Node>> graph(n);

        // Add edges and weights to the graph
        graph[0].push_back({1, 4});
        graph[0].push_back({2, 1});
        graph[1].push_back({3, 1});
        graph[2].push_back({1, 2});
        graph[2].push_back({3, 5});
        graph[3].push_back({4, 3});

        int startNode = 0; // Starting node for Dijkstra's algorithm

        // Perform Dijkstra's algorithm
        dijkstra(graph, startNode);

        return 0;
    }
