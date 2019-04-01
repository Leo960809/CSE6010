#include <stdio.h>
#include <stdlib.h>

#include "components.h"


int main(int argc, char *argv[]) {
    char *infile = argv[1];
    char *outfile = argv[2];
    
    int count;
    Node **graph = load_graph(infile, &count);
    
    int visited[count];
    for (int i = 0; i < count; i++) {
        visited[i] = 0;
    }
    
    analysis(graph, count, visited, outfile);
    
    return 0;
}
