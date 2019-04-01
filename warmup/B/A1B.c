#include "A1B.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/* Function: Apply for dynamic memory allocation for the matrix. */

/* Apply for the allocation for pointers of rows. */
double **malloc_matrix(int n1, int n2) {
    double **matrix = (double **)malloc(sizeof(double *) * n1);
    /* Apply for the allocation for rows. */
    int i;
    for (i = 0; i < n1; i++) {
        *(matrix + i) = (double *)malloc(sizeof(double) * n2);
    }
    if (matrix == NULL) {
        printf("Malloc ERROR.\n");
        exit(0);
        return NULL;
    }
    return matrix;
}


/* Function: Release the memory of the matrix. */
void free_matrix(int n1, int n2, double **a) {
    int i;
    for (i = 0; i < n1; i++) {
        free(a[i]);
    }
    free(a);
}


/* Function: Fill the matrix. */
void fill_matrix(int n1, int n2, double **a) {
    int i, j;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            /* Fill the matrix with random values between 0.0 and 10.0. */
            a[i][j] = rand() / ((double)(RAND_MAX) / 10);
        }
    }
}


/* Function: Print the matrix. */
void print_matrix(int n1, int n2, double **a) {
    int i, j;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            printf("%lf\t", a[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n\n\n");
}


/* Fuction: Multiplication of matrices. */
int matrix_multiply(int n1, int n2, int n3,
                    double **a, double **b, double **c) {
    int i, j, k;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n3; j++) {
            for (k = 0; k < n2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    if (c != NULL) {
        return 0;
    }
    else {
        printf("Calculation ERROR.");
        return 1;
    }
}

int main() {
    double **A, **B, **C;
    
    A = malloc_matrix(4, 3);
    B = malloc_matrix(3, 2);
    C = malloc_matrix(4, 2);
    
    srand((unsigned)time(NULL)); /* Initialize the random process. */
    
    fill_matrix(4, 3, A);
    print_matrix(4, 3, A);
    
    fill_matrix(3, 2, B);
    print_matrix(3, 2, B);
    
    matrix_multiply(4, 3, 2, A, B, C);
    print_matrix(4, 2, C);
    
    free_matrix(4, 3, A);
    free_matrix(3, 2, B);
    free_matrix(4, 2, C);
    
    return 0;
}

