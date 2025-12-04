#include <iostream>
using namespace std;
#define MAX 50
#define INF 999999

void dijkstra(int cost[MAX][MAX], int n, int start) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[start] = 0;

    for (int c = 0; c < n - 1; c++) {
        int min = INF, u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] <= min)
                min = dist[i], u = i;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && cost[u][v] && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < n; i++)
        cout << i << "\t" << dist[i] << "\n";
}

int main() {
    int n, start;
    int cost[MAX][MAX];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter cost adjacency matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> cost[i][j];
    cout << "Enter source vertex: ";
    cin >> start;
    dijkstra(cost, n, start);
    return 0;
}
