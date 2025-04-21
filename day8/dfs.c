#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef enum
{
    WHITE,
    GRAY,
    BLACK
} Color;

typedef struct vertices
{
  int id;
  Color color;
  int d;
  int f;
  struct vertices* pi;
  
}Ver;

typedef struct graph
{
  int V;
  int** adjmat;
  Ver* vertices;
}Graph;

int dfstime=0;

Graph* creategraph(int v)
{
  Graph* g=(Graph*)malloc(sizeof(Graph));
  g->V=v;
  g->adjmat=(int**)malloc(v*sizeof(int*));
  g->vertices = (Ver *)malloc(v * sizeof(Ver));
  for (int i = 0; i < v; i++)
    {
        g->vertices[i].id = i;
        g->adjmat[i] = (int *)calloc(v, sizeof(int));
    }
    return g;
}

void DFSVISIT(Graph* G, Ver* u)
{
  printf("%d ",u->id);
  int v;
  dfstime++;
  u->d=dfstime;
  u->color= GRAY;
  
  for(v=0;v<G->V;v++)
  {
    if(G->adjmat[u->id][v] && G->vertices[v].color==WHITE)
    {
      G->vertices[v].pi=u;
      DFSVISIT(G,&G->vertices[v]);
    }
  }
  u->color = BLACK;
  dfstime++;
  u->f = dfstime;
}

void DFS(Graph* G)
{
    int i;
    for(i=0;i<G->V;i++)
    {
      G->vertices[i].color = WHITE;
      G->vertices[i].pi = NULL;
    }
    
    dfstime=0;
    
    for(i=0;i<G->V;i++)
    {
      if(G->vertices[i].color==WHITE)
      {
        DFSVISIT(G,&G->vertices[i]);
      }
    } 
}
int main()
{
  int v,i,j;
  printf("Enter number of vertices : ");
  scanf("%d",&v);
  
  Graph* G= creategraph(v);
  
  printf("Enter Adjacency Matrix:\n");
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            scanf("%d", &G->adjmat[i][j]);
        }
    }
  
  printf("the values are traversed in order : ");
  clock_t start = clock();
    DFS(G);
    clock_t end = clock();

    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("\nTime taken = %lf seconds\n", timetaken);
  return 0;
}
