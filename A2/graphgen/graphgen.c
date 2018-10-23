
#include "graphgen.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Apply for the allocation for the grids.
int **malloc_grids(int row) {
    int **grids = malloc(sizeof(int *) * row);
    int i;
    for (i = 0; i < row; i++) {
        *(grids + i) = malloc(sizeof(int) * row);
    }
    if (grids == NULL) {
        printf("ERROR.\n");
        exit(0);
        return NULL;
    }
    return grids;
}


// Function: Color the cells in the grids.
void fill_grids(int row, int **A, double p) {
    srand((unsigned)time(NULL));
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++) {
            // Color the cell with probability p.
            A[i][j] = rand() % 100 + 0;
            if (A[i][j] < 100 * p)  A[i][j] = 0; // Color. (0)
            else  A[i][j] = -1; // Uncolor. (-1)
        }
    }
}


void graphgen(int row, double p, const char *filename) {
    int **A;
    // Generate the grids.
    A = malloc_grids(row);
    fill_grids(row, A, p);
    
    // Count the number of vertices.
    int i, j;
    int count = 0; // The numbe of vertices (count).
    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++) {
            if (A[j][i] == 0)  count += 1;
            else  continue;
        }
    }
    
    // Create an array for the data of vertices.
    int list[count][3];
    // Renumber the vertices.
    int n = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++) {
            if (A[j][i] == 0) {
                list[n][0] = n; // Fisrt column is the ordinal number of vertices.
                list[n][1] = j; // The second column is the X-axis.
                list[n][2] = i; // The third column is the Y-axis.
                n += 1;
            }
            else  continue;
        }
    }
    
    
    FILE *f = NULL;
    f = fopen(filename, "w+");
    
    // Print the list that demonstrates all pairs of neighbour vertices.
    printf("%d\n", count);
    fprintf(f, "%d\n", count);
    
    for (i = 0; i< count; i ++) {
        printf("%d ", list[i][0]);
        fprintf(f, "%d ", list[i][0]);
        for (j = 0; j < count; j ++) {
            // Vertice j is to the left or right of Vertice i.
            if (abs(list[i][1] - list[j][1]) == 1 && abs(list[i][2] - list[j][2]) == 0) {
                printf("%d ", list[j][0]);
                fprintf(f, "%d ", list[j][0]);
            }
            // Vertice j is to the up or down of Vertice i.
            if (abs(list[i][1] - list[j][1]) == 0 && abs(list[i][2] - list[j][2]) == 1) {
                printf("%d ", list[j][0]);
                fprintf(f, "%d ", list[j][0]);
            }
            else
                continue;
        }
        printf("\n");
        fprintf(f, "\n");
    }
    fclose(f);
}



