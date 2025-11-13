#include <iostream>
using namespace std;

#define MAX 100  // Maximum number of vertices
#define MAX_EDGES 1000


class Queue {
private:
    int arr[MAX];
    int front, rear;
public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return -1;
        }
        return arr[front++];
    }
};


class Graph {
public:
    int adj[MAX][MAX];   
    int vertices;        
    int edges[MAX];     

    Graph(int v) {
        vertices = v;
        for (int i = 0; i < v; i++) {
            edges[i] = 0;
            for (int j = 0; j < v; j++)
                adj[i][j] = 0;
        }
    }

    void addEdge(int u, int v) {
        adj[u][edges[u]++] = v;
        adj[v][edges[v]++] = u; 
    }

    void BFS(int start) {
        bool visited[MAX];
        for (int i = 0; i < vertices; i++)
            visited[i] = false;

        Queue q;
        visited[start] = true;
        q.enqueue(start);

        cout << "BFS traversal: ";

        while (!q.isEmpty()) {
            int node = q.dequeue();
            cout << node << " ";

            for (int i = 0; i < edges[node]; i++) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.enqueue(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    g.BFS(start);

    return 0;
}
