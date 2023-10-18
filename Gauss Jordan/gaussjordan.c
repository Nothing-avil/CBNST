#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double mat[n][n + 1];

    // Input the augmented matrix
    printf("Enter the coefficients and constants:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("mat[%d][%d]: ", i, j);
            scanf("%lf", &mat[i][j]);
        }
    }

    // Gaussian Elimination with partial or complete pivoting
    for (int i = 0; i < n; i++) {
        // Partial or complete pivoting
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

        double pivot = mat[i][i];
        for (int j = i; j <= n; j++) {
            mat[i][j] /= pivot;
        }

        for (int j = 0; j < n; j++) {
            if (j != i) {
                double factor = mat[j][i];
                for (int k = i; k <= n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }
    }

    // Output the solutions
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %lf\n", i, mat[i][n]);
    }

    return 0;
}
