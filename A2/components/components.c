#include "components.h"

#include <stdio.h>
#include <stdlib.h>



// Function to create a new empty linked list.
Node *create_list(void) {
    Node *list = (Node *)malloc(sizeof(Node));
    list->next = NULL;
    return list;
}

// Function to insert a new node to the linked list.
void insert_list(Node *list, int val) {
    Node *temp;
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = val;
    new->next = NULL;
    temp = list;
    // Insert the new node into the list as the last one.
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

// Function to print the linked list.
void print_list(Node *list) {
    Node *temp;
    temp = list->next;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
}


// Function to generate the graph.
Node **load_graph(const char *filename, int *count) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("ERROR in open file: %s.\n", filename);
        return NULL;
    }
    
    // The first line is the total number of vertices.
    // Apply for enough space (50).
    char str_count[50];
    fgets(str_count, 50, f);
    *count = atoi(str_count);
    
    // Generate the graph.
    Node **graph = (Node **)malloc(*count * sizeof(Node *));
    // Generate a linkded list for each line of the graph.
    for (int i = 0; i < *count; i++)
        graph[i] = create_list();
    
    char str_list[50];
    char temp_list[5][50];
    // Five rows for 5 (at most) data in a linked list.
    for (int i = 0; i < *count; i++) {
        // Initialize the temp_list for each line.
        for (int n = 0; n < 5; n++) {
            for (int k = 0; k < 50; k++) {
                // temp-list to save each elements in the linked list.
                temp_list[n][k] = 'a';
            }
        }
        
        // Read data from each line and put them into str_list.
        fgets(str_list, 50, f);
        int j = 0;
        int n = 0;
        int k = 0;
        while (str_list[j] >= '0' && str_list[j] <= '9') {
            temp_list[n][k] = str_list[j];
            j++;
            k++;
            if (str_list[j] == ' ') {
                insert_list(graph[i], atoi(temp_list[n]));
                n++;
                j++;
                k = 0; // IMPORTANT! Initialize the column of temp_list[n][k].
                continue;
            }
            else if (str_list[j] == '\n') {
                printf("%s\n", temp_list[n]);
                insert_list(graph[i], atoi(temp_list[n]));
                break;
            }
        }
        print_list(graph[i]);
        printf("\n");
    }
    fclose(f);
    return graph;
}


// Depth First Search.
void DFS(Node **graph, int v, int visited[], int *size) {
    Node *p;
    p = graph[v]->next;
    visited[v] = 1;
    *size += 1;
    while (p != NULL) {
        v = p->data;
        if (visited[v] == 0) {
            DFS(graph, v, visited, size);
        }
        p = p->next;
    }
}


void analysis(Node **graph, int count, int visited[], const char *filename) {
    int A[100]; // The size of each components.
    // Initialize.
    for (int i = 0; i < 100; i++)
        A[i] = 0;
    
    int n = 0;
    for (int i = 0; i < count; i++) {
        int size = 0;
        if (visited[i] == 0)
            DFS(graph, i, visited, &size);
        A[n] = size;
        n++;
    }
    
    int max = 0;
    int size_num = 0; // The number of components;
    for (int i = 0; i < 100; i++) {
        if (A[i] != 0) {
            size_num++;
        }
        if (A[i] > max)
            max = A[i];
    }
    
    
    int total[size_num];
    int sum = 0;
    for (int i = 0; i < size_num; i++) {
        for (int j = 0; j < 100; j++) {
            if (A[j] != 0) {
                total[i] = A[j];
                sum += total[i];
            }
        }
    }
    
    int summary[max][2];
    for (int i = 0; i < max; i++) {
        summary[i][0] = i + 1;
        summary[i][1] = 0;
    }
    
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < 100; j++) {
            if (A[j] == summary[i][0])
                summary[i][1]++;
        }
    }
    
    
    FILE *f = NULL;
    f = fopen(filename, "w+");
    
    printf( "%d\n", size_num);
    fprintf(f, "%d\n", size_num);
    
    printf("%.2f\n", count / (float)size_num);
    fprintf(f, "%.2f\n", count / (float)size_num);
    
    printf("%d\n", max);
    fprintf(f, "%d\n", max);
    
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", summary[i][j]);
            fprintf(f, "%d ", summary[i][j]);
        }
        printf("\n");
        fprintf(f, "\n");
    }
}


