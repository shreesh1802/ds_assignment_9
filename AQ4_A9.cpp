#include <iostream>
using namespace std;

#define MAX 50

int dirX[4] = {-1, 1, 0, 0};
int dirY[4] = {0, 0, -1, 1};

void dfs(int grid[MAX][MAX], int m, int n, int x, int y, int visited[MAX][MAX]) {
    visited[x][y] = 1;

    for (int k = 0; k < 4; k++) {
        int nx = x + dirX[k];
        int ny = y + dirY[k];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
            !visited[nx][ny] && grid[nx][ny] == 1) {
            dfs(grid, m, n, nx, ny, visited);
        }
    }
}

int countIslands(int grid[MAX][MAX], int m, int n) {
    int visited[MAX][MAX];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;

    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(grid, m, n, i, j, visited);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int m, n;
    cout << "Enter grid dimensions (m n): ";
    cin >> m >> n;

    int grid[MAX][MAX];
    cout << "Enter grid values (0 or 1):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int islands = countIslands(grid, m, n);
    cout << "Number of islands: " << islands << "\n";

    return 0;
}
