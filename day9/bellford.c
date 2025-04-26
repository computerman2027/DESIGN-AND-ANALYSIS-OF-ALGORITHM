#include <stdio.h>
#include <stdlib.h>

#define INF 99999 

typedef struct {
    int u, v, weight;
} Edge;


void bellmanFord(Edge edges[], int V, int E, int src) {
    int dist[V];
    
    
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;
    
    
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    
    
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
    
   
    printf("Vertex Distance from Source %d\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("%d \t\t INF\n", i);
        } else {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
}

int main() {
    int V, E, src;
    
    
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    
    Edge edges[E];
    
 
    printf("Enter the edges (u, v, weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    
   
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    

    bellmanFord(edges, V, E, src);
    
    return 0;
}

