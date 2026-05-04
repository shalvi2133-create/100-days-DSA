#include <stdio.h>

struct Interval {
    int start;
    int end;
};

void swap(struct Interval *a, struct Interval *b) {
    struct Interval temp = *a;
    *a = *b;
    *b = temp;
}

void sortIntervals(struct Interval arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].start > arr[j + 1].start) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Interval arr[100];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    sortIntervals(arr, n);

    int start = arr[0].start;
    int end = arr[0].end;

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= end) {
            if (arr[i].end > end)
                end = arr[i].end;
        } else {
            printf("%d %d\n", start, end);
            start = arr[i].start;
            end = arr[i].end;
        }
    }

    printf("%d %d", start, end);

    return 0;
}