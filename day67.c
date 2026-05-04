/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int v, struct Node* adj[], int visited[], int stack[], int *top) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data])
            dfs(temp->data, adj, visited, stack, top);
        temp = temp->next;
    }

    stack[++(*top)] = v;
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;
    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int stack[n], top = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, adj, visited, stack, &top);
    }

    printf("Topological Order: ");
    while (top >= 0)
        printf("%d ", stack[top--]);

    return 0;
}