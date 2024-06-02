#include<iostream>
#include<limits>
#include<vector>
using namespace std;

int min_distance(vector<int> &dist, vector<bool> spt_set, int vertices){
    int min = numeric_limits<int>::max();
    int min_idx = -1;

    for(int i=0;i<vertices;i++){
        if(!spt_set[i] && dist[i] <= min){
            min = dist[i];
            min_idx = i;
        }
    }
    return min_idx; // Add return statement
}

void print(vector<int> &dist,int vertices){
    cout<<"Vertex\tDistance from source"<<endl;
    for(int i=0;i<vertices;i++){
        cout<<i<<"\t"<<dist[i]<<endl;
    }
}

vector<int> djikstras_algorithm(int** graph, int vertices){
    vector<int> result(vertices, numeric_limits<int>::max()); // Fix typo in numeric_limits
    vector<bool> spt_set(vertices,false); // visited
    vector<int> dist(vertices);
    dist[0] = 0;

    for(int i = 0; i<vertices - 1;i++){
        int min = min_distance(dist, spt_set, vertices);
        spt_set[min] = true;

        for(int j=0; j<vertices; j++){
            if(
                !spt_set[j] && 
                graph[min][j] && 
                dist[min] != numeric_limits<int>::max() &&
                dist[min] + graph[min][j] < dist[j]){
                    dist[j] = dist[min] + graph[min][j];
                }
        }
    }

    return dist;
}

int main(){
    int vertices;
    cin>> vertices;

    int **graph = new int *[vertices];

    for(int i=0; i<vertices; i++){
        graph[i] = new int[vertices];

        for(int j=0;j<vertices;j++){
            cin>>graph[i][j];
        }
    }
    vector<int> dist = djikstras_algorithm(graph, vertices);0
    print(dist, vertices);
    return 0;
}