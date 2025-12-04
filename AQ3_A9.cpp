#include <iostream>
using namespace std;

#define MAX 50
#define INF 999999

int networkDelayTime(int edges[MAX][3], int E, int N, int K) {
    int cost[MAX][MAX];
    int dist[MAX];
    int visited[MAX];


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) cost[i][j] = 0;
            else cost[i][j] = INF;
        }
    }

  
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        cost[u][v] = w; 
    }

    
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[K] = 0;

    for (int count = 1; count <= N - 1; count++) {
        int min = INF, u = -1;

      
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break; 
        visited[u] = 1;

        
        for (int v = 1; v <= N; v++) {
            if (!visited[v] && cost[u][v] != INF &&
                dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    int maxDelay = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) return -1; 
        if (dist[i] > maxDelay)
            maxDelay = dist[i];
    }
    return maxDelay;
}

int main() {
    int N, E, K;
    cout << "Enter number of nodes (N), edges (E), and starting node (K): ";
    cin >> N >> E >> K;

    int edges[MAX][3];
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int result = networkDelayTime(edges, E, N, K);
    cout << "Network Delay Time: " << result << "\n";
    return 0;
}
