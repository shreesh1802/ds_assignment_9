#include <iostream>
using namespace std;
#define MAX 50

void DFSUtil(int adj[MAX][MAX], int n, int v, int visited[MAX]) {
    visited[v] = 1;
    cout << v << " ";
    for (int i = 0; i < n; ++i) {
        if (adj[v][i] && !visited[i])
            DFSUtil(adj, n, i, visited);
    }
}

void DFS(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    cout << "DFS Traversal: ";
    DFSUtil(adj, n, start, visited);
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int adj[MAX][MAX];
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];

    int start;
    cout << "Enter start vertex: ";
    cin >> start;

    DFS(adj, n, start);
    return 0;
}
