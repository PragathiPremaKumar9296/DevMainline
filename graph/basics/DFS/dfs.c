#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** array;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for(int i = 0; i < vertices; i++)
        graph->array[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* node = createNode(dest);
    node->next = graph->array[src];
    graph->array[src] = node;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* temp = graph->array[i];
        printf("vertix: %d",i);
        while(temp) {
            printf("-> %d ", temp->data);
            temp = temp->next;
        }
         printf("\n");
    }
}

void DFS(struct Graph* graph, int start_vertex, bool visited[]){
    struct Node* temp = graph->array[start_vertex];
    visited[start_vertex] = true;
    printf("%d ", start_vertex);

    while(temp) {
        int adjacentNode = temp->data;
        if (!visited[adjacentNode])
            DFS(graph, adjacentNode, visited);
        temp = temp->next;
    }
}

void DFS_traversal(struct Graph* graph, int start_vertex) {
    bool* visited = (bool*)malloc(sizeof(bool) * graph->vertices);
    
    if (visited == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for(int i = 0; i < graph->vertices; i++)
        visited[i] = false;
    
    DFS(graph, start_vertex, visited);
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* current = graph->array[i];
        while (current) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}


int main() {
    int vertices = 4;
    struct Graph* graph = createGraph(vertices);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 3); // Self-loop

    // Print the adjacency list representation
    printf("Adjacency List Representation of the Graph:\n");
    printGraph(graph);

    return 0;
}