#include <iostream>
using namespace std;
#define MAX 50
#define INF 999999

int findParent(int parent[MAX], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int parent[MAX], int i, int j) {
    int a = findParent(parent, i);
    int b = findParent(parent, j);
    parent[a] = b;
}

void kruskal(int cost[MAX][MAX], int n) {
    int parent[MAX];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int edge_count = 0, mincost = 0;
    cout << "Edge : Weight\n";
    while (edge_count < n - 1) {
        int min = INF, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (findParent(parent, i) != findParent(parent, j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        unionSet(parent, a, b);
        cout << a << " - " << b << " : " << min << "\n";
        mincost += min;
        edge_count++;
    }
    cout << "Minimum Cost = " << mincost << "\n";
}

int main() {
    int n;
    int cost[MAX][MAX];
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter cost adjacency matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> cost[i][j];
    kruskal(cost, n);
    return 0;
}
