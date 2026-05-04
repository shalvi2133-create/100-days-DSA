/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int main() {
    int n, i, x;
    scanf("%d", &n);

    struct ListNode *head = NULL, *temp = NULL, *newNode;

    for (i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    return 0;
}