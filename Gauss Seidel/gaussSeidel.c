#include <stdio.h>
#include <math.h>

int n;
int step=1;
void calFunction(float mat[][100], float x , float y , float z){
    float x1 = (mat[0][3]-y*mat[0][1]-z*mat[0][2])/mat[0][0];
    float y1 = (mat[1][3]-x1*mat[1][0]-z*mat[1][2])/mat[1][1];
    float z1 = (mat[2][3]-x1*mat[2][0]-y1*mat[2][1])/mat[2][2];

    printf("%d\t\t%0.4f\t%0.4f\t%0.4f\n" , step , x1, y1 , z1);

    float e1 = fabs(x - x1);
    float e2 = fabs(y - y1);
    float e3 = fabs(z - z1);

    step++;

    if(e1 <= 0.0001 && e2 <= 0.0001 && e3 <= 0.0001 ){
        printf("The value of x =  %0.4f , y = %0.4f and z = %0.4f", x1 , y1 , z1);
        return;
    }

    calFunction(mat, x1, y1, z1);    
}

int main() {
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    float mat[100][100];

    printf("Enter the coefficients and constants:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("mat[%d][%d]: ", i, j);
            scanf("%f", &mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        float diag = mat[i][i];
        int max_row = i;

        for (int j = i + 1; j < n; j++) {
            if (fabs(mat[j][i]) > fabs(mat[max_row][i])) {
                max_row = j;
            }
        }

        if (max_row != i) {
            // Swap equations to ensure diagonal dominance
            for (int k = 0; k < n + 1; k++) {
                float temp = mat[i][k];
                mat[i][k] = mat[max_row][k];
                mat[max_row][k] = temp;
            }
        }
    }

    printf("Modified Matrix (Diagonal Dominance):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }
    float g;
    printf("Enter the initial guess for the equation:\n");
    scanf("%f", &g);
    
    printf("Solving using Gauss-Seidel method...\n");
    calFunction(mat, g, g, g);

    return 0;
}
