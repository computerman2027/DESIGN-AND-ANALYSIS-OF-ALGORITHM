#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define INF INT_MAX

void printSolution(int **dist, int V,int d)
{
    int i,j;
    printf("\nD%d predecessor matrix:\n",d);
    for (i = 0; i < V; i++)
    {   
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s\t", "INF");
            else
                printf("%7d\t", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int **graph, int V)
{
    int **dist;
    int i,j,k,d=0;

    dist = (int **)malloc(V * sizeof(int *));
    for (i = 0; i < V; i++)
        dist[i] = (int *)malloc(V * sizeof(int));

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    printSolution(dist, V,d);
    d++;
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        printSolution(dist, V,d);
        d++;
    }

    //printSolution(dist, V);

    for (i = 0; i < V; i++)
        free(dist[i]);
    free(dist);
}

int main()
{
    int V,i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int **graph = (int **)malloc(V * sizeof(int *));
    for (i = 0; i < V; i++)
        graph[i] = (int *)malloc(V * sizeof(int));

    printf("Enter the adjacency matrix :\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
            {
                graph[i][j] = INF;
            }
        }
    }
    
    clock_t s = clock();
    floydWarshall(graph, V);
    clock_t e = clock();

    double tt = ((double)(e - s)) / CLOCKS_PER_SEC;
    printf("Time taken : %lf s\n", tt);

    for (i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
