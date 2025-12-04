#include <iostream>
using namespace std;

#define MAX 50


void dfs(int adj[MAX][MAX], int V, int u, int visited[MAX]) {
    visited[u] = 1;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] == 1 && visited[v] == 0)
            dfs(adj, V, v, visited);
    }
}


int countComponents(int adj[MAX][MAX], int V) {
    int visited[MAX];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int count = 0;
    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            dfs(adj, V, i, visited);
            count++;
        }
    }
    return count;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    int adj[MAX][MAX];
    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    int result = countComponents(adj, V);
    cout << "Number of connected components: " << result << "\n";

    return 0;
}
