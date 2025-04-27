#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define INF INT_MAX

int mindist(int dist[], int visited[], int V)
{
    int v, min = INF, minindex;

    for (v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            minindex = v;
        }
    }
    return minindex;
}

void dijkstra(int **graph, int V, int src)
{
    int *dist = (int *)malloc(V * sizeof(int));
    int *visited = (int *)malloc(V * sizeof(int));

    int i, count, u, v;

    for (i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (count = 0; count < V - 1; count++)
    {
        u = mindist(dist, visited, V);
        visited[u] = 1;
        for (v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex distance from Source %d :\n", src);

    printf("Destination\t\tDistance\n");
    for (i = 0; i < V; i++)
    {
        if (dist[i] == INF)
        {
            printf("%11d\t\tINF\t\n", i);
        }
        else
        {
            printf("%11d\t\t%-8d\t\n", i, dist[i]);
        }
    }
}

int main()
{

    int V;
    printf("Enter no of vertex : ");
    scanf("%d", &V);

    int **graph = (int **)malloc(V * sizeof(int *));
    int i, j;

    for (i = 0; i < V; i++)
    {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    printf("Enter data :\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex : ");
    scanf("%d", &source);

    clock_t s = clock();
    dijkstra(graph, V, source);
    clock_t e = clock();

    double tt = ((double)(e - s)) / CLOCKS_PER_SEC;
    printf("Tiem taken : %lf s\n", tt);

    return 0;
}