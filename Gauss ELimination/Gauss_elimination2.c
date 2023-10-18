#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double mat[n][n + 1];

    printf("Enter the coefficients and constants:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("mat[%d][%d]: ", i, j);
            scanf("%lf", &mat[i][j]);
        }
    }

    // Gaussian Elimination with complete pivoting
    for (int i = 0; i < n; i++) {
        int max_row = i, max_col = i;
        for (int k = i; k < n; k++) {
            for (int l = i; l < n; l++) {
                if (fabs(mat[k][l]) > fabs(mat[max_row][max_col])) {
                    max_row = k;
                    max_col = l;
                }
            }
        }

        // Swap rows
        for (int k = i; k <= n; k++) {
            double temp = mat[i][k];
            mat[i][k] = mat[max_row][k];
            mat[max_row][k] = temp;
        }

        // Swap columns
        for (int k = 0; k < n; k++) {
            double temp = mat[k][i];
            mat[k][i] = mat[k][max_col];
            mat[k][max_col] = temp;
        }

        for (int j = i + 1; j < n; j++) {
            double factor = mat[j][i] / mat[i][i];
            for (int k = i; k <= n; k++) {
                mat[j][k] -= factor * mat[i][k];
            }
        }
    }

    // Backward substitution
    double x[n];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = mat[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] /= mat[i][i];
    }

    // Output the solutions
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %lf\n", i, x[i]);
    }

    return 0;
}
