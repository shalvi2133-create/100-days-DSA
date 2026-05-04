#include <stdio.h>

struct Meeting {
    int start;
    int end;
};

void swap(struct Meeting *a, struct Meeting *b) {
    struct Meeting temp = *a;
    *a = *b;
    *b = temp;
}

void sortMeetings(struct Meeting arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].start > arr[j + 1].start) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index]) {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;
        } else
            break;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            int temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;
            index = smallest;
        } else
            break;
    }
}

void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    heapifyUp(heap, *size);
    (*size)++;
}

void deleteMin(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Meeting arr[100];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    sortMeetings(arr, n);

    int heap[100];
    int heapSize = 0;

    insertHeap(heap, &heapSize, arr[0].end);

    int maxRooms = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= heap[0]) {
            deleteMin(heap, &heapSize);
        }

        insertHeap(heap, &heapSize, arr[i].end);

        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }

    printf("%d", maxRooms);

    return 0;
}