/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int adj[n][n], indegree[n];

    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    int u, v;
    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        if (!adj[u][v]) {
            adj[u][v] = 1;
            indegree[v]++;
        }
    }

    int queue[n], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    printf("Topological Order: ");
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < n; i++) {
            if (adj[curr][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    return 0;
}