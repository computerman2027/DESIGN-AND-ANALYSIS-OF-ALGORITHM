#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define INF INT_MAX

typedef struct
{
    int u, v, wt;
} Edge;

void bellmanFord(Edge edges[], int V, int E, int src)
{
    int *dist = (int *)malloc(V * sizeof(int));
    int i, j, u, v, wt;

    for (i = 0; i < V; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0;

    for (i = 1; i <= V - 1; i++)
    {
        for (j = 0; j < E; j++)
        {
            u = edges[j].u;
            v = edges[j].v;
            wt = edges[j].wt;

            if (dist[u] != INF && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (i = 0; i < E; i++)
    {
        u = edges[i].u;
        v = edges[i].v;
        wt = edges[i].wt;

        if (dist[u] != INF && dist[u] + wt < dist[v])
        {
            printf("Graph contains negative weight cycle\n");
            return;
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
    int V, E = 0, i, j, k = 0, src;

    printf("Enter no of Vertices : ");
    scanf("%d", &V);

    int **adj = (int **)malloc(V * sizeof(int *));

    for (i = 0; i < V; i++)
    {
        adj[i] = (int *)malloc(V * sizeof(int));
    }

    printf("Enter Graph data :\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] != 0)
                E++;
        }
    }

    Edge *edges = (Edge *)malloc(E * sizeof(Edge));

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (adj[i][j] != 0)
            {
                edges[k].u = i;
                edges[k].v = j;
                edges[k].wt = adj[i][j];
                k++;
            }
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);
    clock_t s = clock();
    bellmanFord(edges, V, E, src);
    clock_t e = clock();
    double tt = ((double)(e - s)) / CLOCKS_PER_SEC;
    printf("Tiem taken : %lf s\n", tt);
    return 0;
}