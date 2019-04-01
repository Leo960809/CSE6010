#ifndef A1B_h
#define A1B_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double **malloc_matrix(int n1, int n2);
void free_matrix(int n1, int n2, double **a);
void fill_matrix(int n1, int n2, double **a);
void print_matrix(int n1, int n2, double **a);
int matrix_multiply(int n1, int n2, int n3, double **a, double **b, double **c);


#endif /* A1B_h */
