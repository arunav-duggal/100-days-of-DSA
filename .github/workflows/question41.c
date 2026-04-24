#include <stdio.h>
#define NODES 4
void initMatrix(int adjMatrix[NODES][NODES]) 
{
    for (int i = 0; i < NODES; i++) 
    {
        for (int j = 0; j < NODES; j++) 
        {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int adjMatrix[NODES][NODES], int u, int v) 
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void printMatrix(int adjMatrix[NODES][NODES]) 
{
    printf("Adjacency Matrix (4 Nodes):\n\n");
    for (int i = 0; i < NODES; i++) 
    {
        for (int j = 0; j < NODES; j++) 
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}
int main() 
{
    int adjMatrix[NODES][NODES];
    initMatrix(adjMatrix);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 2, 3);
    printMatrix(adjMatrix);
    return 0;
}
