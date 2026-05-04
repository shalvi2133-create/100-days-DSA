/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node *head1 = NULL, *tail1 = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head1 == NULL) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);
    struct Node *head2 = NULL, *tail2 = NULL;

    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head2 == NULL) {
            head2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    int len1 = 0, len2 = 0;
    struct Node* temp = head1;
    while (temp != NULL) {
        len1++;
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL) {
        len2++;
        temp = temp->next;
    }

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff--) p1 = p1->next;
    } else {
        int diff = len2 - len1;
        while (diff--) p2 = p2->next;
    }

    int found = 0;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data == p2->data) {
            printf("%d", p1->data);
            found = 1;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    if (!found) {
        printf("No Intersection");
    }

    return 0;
}