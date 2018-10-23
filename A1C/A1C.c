#include "A1C.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20


// Function to create an empty priority queue
PrioQ *PQ_create() {
    PrioQ *head = malloc(sizeof(PrioQ));
    if (head == NULL) {
        printf("ERROR\n");
        return NULL;
    }
    return head;
}


// Function to insert a new element
int PQ_insert(PrioQ *PQ, double key, void *data) {
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    new->key = key;
    
    if (PQ->head == NULL) {
        PQ->head = new;
        PQ->tail = new;
        return 0;
    }
    
    Node *temp = PQ->head;
    if (PQ->head->key > key) {
        PQ->head = new;
        new->next = temp;
        return 0;
    }
    
    while (temp->key <= key) {
        PQ->tail = temp;
        temp = temp->next;
        if (temp == NULL) {
            break;
        }
    }
    
    if (PQ == NULL) {
        printf("ERROR");
        return NULL;
    }
    
    new->next = temp;
    PQ->tail->next = new;
    PQ->tail = PQ->head; // this step is used for PQfree();
    return 0;
}


// Delete the item with the highest priority
void *PQ_delete(PrioQ *PQ, double *key) {
    if (PQ->head == NULL) {
        printf("Empty Queue\n");
        return NULL;
    }
    
    void *rest = PQ->head->data;
    *key = PQ->head->key;
    PQ->head = PQ->head->next;
    return rest;
}


// Count the number of residing items
unsigned int PQ_count(PrioQ *PQ) {
    if (PQ->head == NULL) {
        return 0;
    }
    
    Node *count = PQ->head;
    int number = 0;
    while (count != NULL) {
        count = count->next;
        number++;
    }
    return number;
}


// Release the memory
void *PQ_free(PrioQ *PQ) {
    if (PQ == NULL) {
        printf("Empty Queue\n");
    }
    Node *curr;
    while (PQ->tail != NULL) {
        curr = PQ->tail;
        PQ->tail = PQ->tail->next;
        free(curr);
    }
    free(PQ->head);
    return NULL;
}

int main() {
    srand((unsigned)time(NULL));
    double data[MAX];
    double key[MAX];
    
    printf("Generated Data: \n\n");
    int i;
    for (i = 0; i < MAX; i++) {
        // Value: random float number between 0.0 and 10.0
        data[i] = rand() / (double)(RAND_MAX / 10);
        // Priority: randome float number between 0.0 and 20.0
        key[i] = rand() / (double)(RAND_MAX / 20);
        
        printf("\tValue: %f\n", data[i]);
        printf("\tPriority: %f\n\n", key[i]);
    }
    
    // Create an empty queue
    PrioQ *PQ = PQ_create();
    
    // Insert the elements
    for (i = 0; i < MAX; i++) {
        PQ_insert(PQ, key[i], &data[i]);
    }
    
    // Print the verification process
    printf("Verification: \n\n");
    for (i = 0; i < MAX; i++) {
        double *rest = PQ_delete(PQ, key);
        printf("\tValue of the Deleted Item: %f\n", *rest);
        printf("\tPriority of the Deleted Item: %f\n\n", key[0]);
    }
    
    // Release the memory and delete the priority queue
    PQ_free(PQ);
    return 0;
}
