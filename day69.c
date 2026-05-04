/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node {
    int v, weight;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = adj[v];
    adj[v] = newNode;
}

struct HeapNode {
    int v, dist;
};

struct Heap {
    int size;
    struct HeapNode arr[MAX];
};

void swap(struct HeapNode *a, struct HeapNode *b) {
    struct HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(struct Heap *h, int i) {
    while (i && h->arr[i].dist < h->arr[(i - 1) / 2].dist) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(struct Heap *h, int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;
    if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(struct Heap *h, int v, int dist) {
    h->arr[h->size].v = v;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

struct HeapNode pop(struct Heap *h) {
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapifyDown(h, 0);
    return root;
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int u, v, w;
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    int dist[n];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    struct Heap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while (h.size > 0) {
        struct HeapNode node = pop(&h);
        int u = node.v;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Shortest distances from source:\n");
    for (int i = 0; i < n; i++)
        printf("%d -> %d = %d\n", src, i, dist[i]);

    return 0;
}