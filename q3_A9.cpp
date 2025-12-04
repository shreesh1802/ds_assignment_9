#include <iostream>
using namespace std;
#define INF 999999
#define MAX 50

void prims(int cost[MAX][MAX], int n) {
    int selected[MAX] = {0};
    int no_edge = 0;
    selected[0] = 1; 

    cout << "Edge : Weight\n";
    while (no_edge < n - 1) {
        int min = INF, x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j]) {
                        if (min > cost[i][j]) {
                            min = cost[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " : " << cost[x][y] << "\n";
        selected[y] = 1;
        no_edge++;
    }
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
    prims(cost, n);
    return 0;
}
