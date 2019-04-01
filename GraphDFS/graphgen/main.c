#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graphgen.h"

int main(int argc, char *argv[]) {
    int row = atoi(argv[1]);
    float p = atof(argv[2]);
    char *filename = argv[3];
    
    graphgen(row, p, filename);
    
    return 0;
}
