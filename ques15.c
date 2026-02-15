#include <stdio.h>

int main() {
    int m, n, i, j;
    int sum = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // sum of primary diagonal
    for(i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    printf("%d", sum);

    return 0;
}
