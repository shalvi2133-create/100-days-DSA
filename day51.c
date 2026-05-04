#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        printf("Inserting %d\n", data);
        return create(data);
    }
    if (data < root->data) {
        printf("Going left from %d\n", root->data);
        root->left = insert(root->left, data);
    } else {
        printf("Going right from %d\n", root->data);
        root->right = insert(root->right, data);
    }
    return root;
}

int lca(struct Node* root, int n1, int n2) {
    if (root == NULL) return -1;

    printf("Visiting node %d\n", root->data);

    if (n1 < root->data && n2 < root->data)
        return lca(root->left, n1, n2);

    if (n1 > root->data && n2 > root->data)
        return lca(root->right, n1, n2);

    return root->data;
}

int main() {
    int n, i, val, n1, n2;
    struct Node* root = NULL;

    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter two nodes:\n");
    scanf("%d %d", &n1, &n2);

    int result = lca(root, n1, n2);

    printf("LCA is: %d\n", result);

    return 0;
}