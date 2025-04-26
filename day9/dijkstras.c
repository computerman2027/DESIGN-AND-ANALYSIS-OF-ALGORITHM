#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX  
int minDistance(int dist[], int visited[], int V) {
    int min = INF, min_index;
    
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}


void dijkstra(int** graph, int V, int src) {
    int dist[V];   
    int visited[V]; 
    

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    
  
    dist[src] = 0;
    
  
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        
        
        visited[u] = 1;
        
        
        for (int v = 0; v < V; v++) {
           
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("%d \t INF\n", i);
        } else {
            printf("%d \t %d\n", i, dist[i]);
        }
    }
}

int main() 
{

    int V;    
    printf("Enter no of vertex : ");
    scanf("%d",&V);
    
    int** graph=(int**)malloc(V*sizeof(int*));
    int i,j;
    
    for(i=0;i<V;i++)
    {
      graph[i]=(int*)malloc(V*sizeof(int));
    }
    
    printf("Enter data : ");
    for(i=0;i<V;i++)
    {
      for(j=0;j<V;j++)
      { 
        scanf("%d",&graph[i][j]);
      }
    }

    int source;
    printf("Enter the source vertex : ");
    scanf("%d", &source);
    
    dijkstra(graph, V, source);
    
    return 0;
}

