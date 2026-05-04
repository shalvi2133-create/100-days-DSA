#include <stdio.h>

int merge(int arr[], int low, int mid, int high) {
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;
    int invCount = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            invCount = invCount + (mid - i + 1);
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

int mergeSort(int arr[], int low, int high) {
    int invCount = 0;

    if (low < high) {
        int mid = (low + high) / 2;

        invCount += mergeSort(arr, low, mid);
        invCount += mergeSort(arr, mid + 1, high);
        invCount += merge(arr, low, mid, high);
    }

    return invCount;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = mergeSort(arr, 0, n - 1);

    printf("%d", result);

    return 0;
}