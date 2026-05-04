#include <stdio.h>

int isPossible(int books[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        if (pagesSum + books[i] <= maxPages) {
            pagesSum += books[i];
        } else {
            students++;
            pagesSum = books[i];

            if (students > m)
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int books[n];
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
        sum += books[i];

        if (books[i] > max)
            max = books[i];
    }

    int low = max;
    int high = sum;
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(books, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}