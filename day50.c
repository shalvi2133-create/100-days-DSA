#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int val) {
    if (root == NULL) {
        printf("Inserted %d\n", val);
        return create(val);
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

void search(struct node* root, int key) {
    if (root == NULL) {
        printf("Element not found\n");
        return;
    }
    if (root->data == key) {
        printf("Element found: %d\n", key);
        return;
    }
    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

int main() {
    struct node* root = NULL;
    int n, val, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    search(root, key);

    return 0;
}