/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int maxLevel = 0;

void rightViewRec(struct Node* root, int level) {
    if (!root) return;
    if (level > maxLevel) {
        printf("%d ", root->data);
        maxLevel = level;
    }
    rightViewRec(root->right, level + 1);
    rightViewRec(root->left, level + 1);
}

struct Node* buildTree(int values[], int n, int index) {
    if (index >= n || values[index] == -1) return NULL;
    struct Node* root = newNode(values[index]);
    root->left = buildTree(values, n, 2 * index + 1);
    root->right = buildTree(values, n, 2 * index + 2);
    return root;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int values[n];
    printf("Enter level-order traversal (-1 for NULL): ");
    for(int i = 0; i < n; i++) scanf("%d", &values[i]);

    struct Node* root = buildTree(values, n, 0);

    printf("Right view nodes: ");
    rightViewRec(root, 1);

    return 0;
}