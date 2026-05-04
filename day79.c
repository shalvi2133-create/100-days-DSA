/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000

int minDistance(int dist[], int visited[], int n) {
    int min = INF, idx = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int n, int** adj, int source) {
    int dist[n+1], visited[n+1];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int i = 1; i <= n; i++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != 0 && !visited[v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    printf("Shortest distances:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &n, &m);

    int** adj = (int**)malloc((n+1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        adj[i] = (int*)calloc(n+1, sizeof(int));
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int source;
    printf("Enter source vertex:\n");
    scanf("%d", &source);

    dijkstra(n, adj, source);

    return 0;
}