/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node {
    int data;
    int hd;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->hd = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    int map[2 * MAX][MAX];
    int count[2 * MAX] = {0};
    int offset = MAX;

    struct Node* queue[MAX];
    int hd[MAX];

    int front = 0, rear = 0;

    root->hd = 0;
    queue[rear] = root;
    hd[rear++] = 0;

    while (front < rear) {
        struct Node* temp = queue[front];
        int h = hd[front];
        front++;

        map[h + offset][count[h + offset]++] = temp->data;

        if (temp->left) {
            queue[rear] = temp->left;
            hd[rear++] = h - 1;
        }

        if (temp->right) {
            queue[rear] = temp->right;
            hd[rear++] = h + 1;
        }
    }

    printf("Vertical Order Traversal:\n");

    for (int i = 0; i < 2 * MAX; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
