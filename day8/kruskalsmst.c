#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct edge
{
    int source;
    int destination;
    int weight;
} Edge;

typedef struct subset
{
    int parent;
    int rank;
} Subset;

int compareEdges(const void *a, const void *b)
{
    return (((Edge *)a)->weight) - (((Edge *)b)->weight);
}

int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalsMST(Edge edges[], int V, int E)
{
    Edge *result = (Edge *)malloc((V - 1) * sizeof(Edge));

    int e = 0;
    int i = 0;
    int v;

    qsort(edges, E, sizeof(edges[0]), compareEdges);

    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));

    for (v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < E)
    {
        Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.source);
        int y = find(subsets, nextEdge.destination);

        if (x != y)
        {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

  int sum=0;
    printf("Edges in the MST:\n");
    for (i = 0; i < e; ++i)
    {    printf("%d -- %d == %d\n", result[i].source, result[i].destination, result[i].weight);
         sum=sum+result[i].weight;
    }
    free(subsets);
    
    printf("Total weight = %d\n",sum);
}

int main()
{
    int V, E;
    printf("Enter no of Vertices : ");
    scanf("%d", &V);
    
    int** adj = (int**)malloc(V*sizeof(int*));
    int i,j;
    for(i=0;i<V;i++)
    {
      adj[i]=(int*)malloc(V*sizeof(int));
    }
    
    printf("Enter adjacency matrix : \n");
    for(i=0;i<V;i++)
    {
      for(j=0;j<V;j++)
      {
        scanf("%d",&adj[i][j]);
      }
    }
    
    E=((V*V)-V)/2;
    
    Edge *edges = (Edge *)malloc(E * sizeof(Edge));
 
    int k = 0;  
    for(i=0;i<V;i++)
    {   
      for(j=i+1;j<V;j++) 
      { 
        if(adj[i][j])
        {
            edges[k].source = i;
            edges[k].destination = j;
            edges[k].weight = adj[i][j];
            k++; 
        }
      }
    }

      
    clock_t start=clock();
    kruskalsMST(edges, V, E);
  clock_t end=clock();
  double time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nCPU TIME: %lf Seconds\n",time);
    return 0;
}
