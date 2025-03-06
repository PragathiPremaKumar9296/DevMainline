#include <stdio.h>
#include <stdlib.h>

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