#ifndef A1C_h
#define A1C_h


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20


// typedef
typedef struct node{
    void *data;
    double key;
    struct node* next;
} Node;


typedef struct pq{
    Node *head;
    Node *tail;
} PrioQ;


// All the functions
PrioQ *PQ_create(void);
int PQ_insert(PrioQ *PQ, double key, void *data);
void *PQ_delete(PrioQ *PQ,double *key);
unsigned int PQ_count(PrioQ *PQ);
void *PQ_free(PrioQ *PQ);



#endif /* A1C_h */
