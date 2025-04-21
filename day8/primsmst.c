#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

typedef struct Graph{
    int v;
    int** adjmat;
}Graph;

int minwt(int* wt,int* vis,int V )
{
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0 && wt[i]<min)
        {
            min=wt[i];
            min_index=i;
        }
    }
    return min_index;
}
void prims(Graph* G)
{
    int V=G->v;
    int* parent=(int*)malloc(V*sizeof(int));
    int* wt=(int*)malloc(V*sizeof(int));
    int* vis=(int*)calloc(V,sizeof(int));
    for(int i=0;i<V;i++)
    {
        wt[i]=INT_MAX;
        parent[i]=-1;
    }
    wt[0]=0;
    for(int e=0;e<V-1;e++)
    {
        int u=minwt(wt,vis,V);
        vis[u]=1;
        for(int v=0;v<V;v++)
        {
            if(G->adjmat[u][v]!=0 && vis[v]==0 && G->adjmat[u][v]<wt[v])
            {
                wt[v]=G->adjmat[u][v];
                parent[v]=u;
            }
        }
    }
    int sum=0;
    printf("Edges in mst :\n");
    for(int i=1;i<V;i++)
    {
        printf("%d -- %d == %d\n",parent[i],i,wt[i]);
        sum+=wt[i];
    }
    printf("\nMinimum Spanning Tree cost is: %d",sum);
}
int main()
{
    Graph *G=(Graph*)malloc(sizeof(Graph));
    printf("Enter no of vertex: ");
    scanf("%d",&G->v);
    G->adjmat=(int**)malloc((G->v)*sizeof(int*));
    for(int i=0;i<G->v;i++)
    {
        G->adjmat[i]=(int*)malloc((G->v)*sizeof(int));
    }
    printf("Enter adjacency matrix : \n");
    for(int i=0;i<G->v;i++)
    {
        for(int j=0;j<G->v;j++)
        {
            scanf("%d",&G->adjmat[i][j]);
        }
    }
    printf("Minimum spanning tree : \n");
    clock_t start=clock();
    prims(G);
    clock_t end=clock();
    double time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nCPU TIME: %lf seconds\n",time);
    return 0;
}
