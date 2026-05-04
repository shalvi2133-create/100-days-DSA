#include <stdio.h>

void sortBucket(float bucket[], int count) {
    for (int i = 1; i < count; i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    float bucket[100][100];
    int count[100] = {0};

    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        bucket[index][count[index]] = arr[i];
        count[index]++;
    }

    for (int i = 0; i < n; i++) {
        sortBucket(bucket[i], count[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k] = bucket[i][j];
            k++;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}