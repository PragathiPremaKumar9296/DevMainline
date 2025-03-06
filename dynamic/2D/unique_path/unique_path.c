#include <stdio.h>

int uniquePaths(int m, int n) {
    int grid[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0)
                grid[i][j] = 1;
            else
                grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
        }
    }
    return grid[m - 1][n - 1];
}

int main() {
    int m = 3, n = 7;
    printf("Unique Paths: %d\n", uniquePaths(m, n));
    return 0;
}