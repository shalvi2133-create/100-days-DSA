#include <stdio.h>

struct Car {
    int pos;
    int speed;
};

void swap(struct Car *a, struct Car *b) {
    struct Car temp = *a;
    *a = *b;
    *b = temp;
}

void sortCars(struct Car arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].pos < arr[j + 1].pos) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int target, n;
    scanf("%d", &target);
    scanf("%d", &n);

    struct Car arr[100];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].pos);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].speed);
    }

    sortCars(arr, n);

    int fleets = 0;
    float maxTime = 0;

    for (int i = 0; i < n; i++) {
        float time = (float)(target - arr[i].pos) / arr[i].speed;

        if (time > maxTime) {
            fleets++;
            maxTime = time;
        }
    }

    printf("%d", fleets);

    return 0;
}