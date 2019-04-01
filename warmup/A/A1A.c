#include "A1A.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define m 5
#define n 5
#define p 0.175


int main()
{
    int array[m][n] = {0};
    int i, j;
    
    srand((unsigned)time(0)); /* Initialize the matrix. */
    
    /* Generate the original matrix. */
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            /**
             In the cell of a(i,j), randomly generate an integer in [0, 1000),
             if the number is in [0, 1000*p), assign array(i,j) to 1,
             else, assign array(i,j) to 0,
             which makes "1" be written with probability p,
             and "0" with (1 - p).
             */
            array[i][j] = rand() % 1000 + 0;
            if (array[i][j] < p * 1000)    array[i][j] = 1;
            else    array[i][j] = 0;
            printf("%d\t", array[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n\n\n");
    
    
    /* Search for "1". */
    int row[m], col[n];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (array[i][j] == 1)
            {
                row[i] = 99; /* The "99" here is just a mark. */
                col[j] = 99; /* Also, "99" as a mark. */
            }
        }
    }
    
    /* Set the entire chosen rows to "1". */
    for (i = 0; i < m; i++)
    {
        if (row[i] == 99)
        {
            for (j = 0; j < n; j++)    array[i][j] = 1;
        }
    }
    
    /* Set the entire chosen columns to "1". */
    for (j = 0; j < n; j++)
    {
        if (col[j] == 99)
        {
            for (i = 0; i < m; i++)    array[i][j] = 1;
        }
    }
    
    /* Print the modified array. */
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n\n");
    }
    
    return 0;
}
