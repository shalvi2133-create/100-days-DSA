/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include <stdio.h>

int deque[100];
int front = -1, rear = -1;

void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
        deque[front] = x;
    } else {
        front--;
        deque[front] = x;
    }
}

void push_back(int x) {
    if (rear == -1) {
        front = rear = 0;
        deque[rear] = x;
    } else {
        rear++;
        deque[rear] = x;
    }
}

void pop_front() {
    if (front == -1 || front > rear) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[front]);
    front++;
}

void pop_back() {
    if (rear == -1 || front > rear) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[rear]);
    rear--;
}

void getFront() {
    if (front == -1 || front > rear) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[front]);
}

void getBack() {
    if (front == -1 || front > rear) {
        printf("-1\n");
        return;
    }
    printf("%d\n", deque[rear]);
}

void isEmpty() {
    if (front == -1 || front > rear)
        printf("1\n");
    else
        printf("0\n");
}

void getSize() {
    if (front == -1 || front > rear)
        printf("0\n");
    else
        printf("%d\n", rear - front + 1);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') {
            int x;
            scanf("%d", &x);
            push_front(x);
        } else if (op[0] == 'p' && op[5] == 'b') {
            int x;
            scanf("%d", &x);
            push_back(x);
        } else if (op[0] == 'p' && op[4] == 'f') {
            pop_front();
        } else if (op[0] == 'p' && op[4] == 'b') {
            pop_back();
        } else if (op[0] == 'f') {
            getFront();
        } else if (op[0] == 'b') {
            getBack();
        } else if (op[0] == 'e') {
            isEmpty();
        } else if (op[0] == 's') {
            getSize();
        }
    }
    return 0;
}