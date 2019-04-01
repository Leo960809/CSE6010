
#ifndef graphgen_h
#define graphgen_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int **malloc_grids(int row);
void fill_grids(int row, int **A, double p);
void graphgen(int row, double p, const char *filename);


#endif /* graphgen_h */
