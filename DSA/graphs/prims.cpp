#include <iostream>
#include <vector>
// #include <climits>
#define INT_MAX 2147483647
using namespace std;

// typedef pair<int, int> pii;
// vector<vector<pii>> graph;

// vector<int> prim(int start) {
//     int n = graph.size();
//     vector<int> dist(n, INT_MAX);
//     vector<bool> visited(n, false);

//     dist[start] = 0;

//     for (int i = 0; i < n - 1; i++) {
//         int u = -1;
//         for (int j = 0; j < n; j++) {
//             if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
//                 u = j;
//             }
//         }

//         visited[u] = true;

//         for (auto edge : graph[u]) {
//             int v = edge.first;
//             int weight = edge.second;

//             if (!visited[v] && weight < dist[v]) {
//                 dist[v] = weight;
//             }
//         }
//     }

//     return dist;
// }

// int main() {
//     int n, m;
//     cout << "Enter the number of nodes: ";
//     cin >> n;
//     cout << "Enter the number of edges: ";
//     cin >> m;

//     graph.resize(n);

//     cout << "Enter the edges in the format (u, v, weight):\n";
//     for (int i = 0; i < m; i++) {
//         int u, v, weight;
//         cin >> u >> v >> weight;
//         graph[u].push_back({v, weight});
//         graph[v].push_back({u, weight});
//     }

//     int start;
//     cout << "Enter the starting node: ";
//     cin >> start;

//     vector<int> dist = prim(start);

//     cout << "Minimum spanning tree distances from node " << start << ":\n";
//     for (int i = 0; i < n; i++) {
//         cout << "Node " << i << ": " << dist[i] << "\n";
//     }

//     return 0;
// }

void Prims(int n){
    int G[n][n] = {{0,9,75,0,0},{9,0,95,19,42},{75,95,0,51,66},{0,19,51,0,31},{0,42,66,31,0}};
    int noEdges = 0;
    int *selected = new int[n];
    selected[0] = 1;
    int x,y,i,j;
    while(noEdges < n-1){
        int min = INT_MAX;
        x=0;y=0;
        for(i=0;i<n;i++){
            if(selected[i]){
                for(j=0;j<n;j++){
                    if(!selected[j] && G[i][j]){
                        if(min > G[i][j]){
                            min = G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        cout<<x<<" "<<y<<" "<<G[x][y]<<endl;
        selected[y] = 1;
        noEdges++;
    }
}

int main(){
    int n = 5;
    Prims(n);
    return 0;
}
