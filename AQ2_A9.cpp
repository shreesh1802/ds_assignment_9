#include <iostream>
using namespace std;

#define MAX 10
#define INF 999999


int dirX[4] = {-1, 1, 0, 0};
int dirY[4] = {0, 0, -1, 1};

void findMinCell(int dist[MAX][MAX], bool visited[MAX][MAX], int m, int n, int &x, int &y) {
    int min = INF;
    x = -1; y = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && dist[i][j] < min) {
                min = dist[i][j];
                x = i; y = j;
            }
        }
    }
}

int shortestPath(int grid[MAX][MAX], int m, int n) {
    int dist[MAX][MAX];
    bool visited[MAX][MAX];

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
            visited[i][j] = false;
        }
    }

    dist[0][0] = grid[0][0]; 

    
    for (int count = 0; count < m * n; count++) {
        int ux, uy;
        findMinCell(dist, visited, m, n, ux, uy);

        if (ux == -1) break; 
        visited[ux][uy] = true;

        
        for (int d = 0; d < 4; d++) {
            int vx = ux + dirX[d];
            int vy = uy + dirY[d];

            
            if (vx >= 0 && vx < m && vy >= 0 && vy < n && !visited[vx][vy]) {
                int newDist = dist[ux][uy] + grid[vx][vy];
                if (newDist < dist[vx][vy])
                    dist[vx][vy] = newDist;
            }
        }
    }

    return dist[m - 1][n - 1];
}

int main() {
    int m, n;
    cout << "Enter grid dimensions (m n): ";
    cin >> m >> n;

    int grid[MAX][MAX];
    cout << "Enter grid values:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    int result = shortestPath(grid, m, n);
    cout << "Minimum total cost: " << result << "\n";
    return 0;
}
