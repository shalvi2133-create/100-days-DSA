#include <stdio.h>

int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + boards[i] <= maxTime) {
            sum += boards[i];
        } else {
            painters++;
            sum = boards[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];

        if (boards[i] > max)
            max = boards[i];
    }

    int low = max;
    int high = sum;
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}