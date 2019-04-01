#ifndef components_h
#define components_h

#include <stdio.h>
#include <stdlib.h>



typedef struct node {
    int data;
    struct node *next;
} Node;


Node *create_list(void);
void insert_list(Node *list, int val);
void print_list(Node *list);
Node **load_graph(const char *filename, int *count);
void DFS(Node **graph, int v, int visited[], int *size);
void analysis(Node **graph, int count, int visited[], const char *filename);


#endif /* components_h */
