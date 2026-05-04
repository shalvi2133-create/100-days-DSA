/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }

    int m;
    printf("Enter number of pops: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--;
        }
    }

    printf("Remaining stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    free(stack);
    return 0;
}