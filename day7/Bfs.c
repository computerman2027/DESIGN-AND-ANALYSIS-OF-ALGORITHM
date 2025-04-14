#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF INT_MAX

typedef struct
{
    int **adjmat;
    int noOfVertices;
} Graph;

typedef struct
{
    int *arr;
    int front, rear, size;
} Queue;

void initilaizeQueue(Queue *q, int size)
{
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc((size) * sizeof(int));
}

void enqueue(Queue *q, int val)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue overflowed\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = val;
}

int dequeue(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue underflow\n");
        return INF;
    }

    int val = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1; // Queue is empty
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }
    return val;
}

int isEmpty(Queue *q)
{
    return q->front == -1 && q->rear == -1 ? 1 : 0;
}

void bfs(Graph *G, int s, int *color, int *d, int *pi)
{
    Queue q;
    initilaizeQueue(&q, G->noOfVertices);

    int i, u, v;

    for (i = 0; i < G->noOfVertices; i++)
    {
        color[i] = WHITE;
        d[i] = INF;
        pi[i] = -1;
    }

    color[s] = GRAY;
    d[s] = 0;
    pi[s] = -1;

    enqueue(&q, s);
    printf("BFS Traversal = ");

    while (!isEmpty(&q))
    {
        u = dequeue(&q);

        printf("%d ", u);

        for (v = 0; v < G->noOfVertices; v++)
        {
            if (G->adjmat[u][v] == 1 && color[v] == WHITE)
            {
                color[v] = GRAY;
                d[v] = d[u] + 1;
                pi[v] = u;
                enqueue(&q, v);
            }
        }
        color[u] = BLACK;
    }

    printf("\n");
}

void printpath(int *pi, int s, int v)
{
    if (v == s)
    {
        printf("%d ", s);
    }
    else if (pi[v] == -1)
    {
        printf("No path from %d to %d exits\n", s, v);
    }
    else
    {
        printpath(pi, s, pi[v]);
        printf("%d ", v);
    }
}

int main()
{
    Graph G;
    int start, end;
    int *color;
    int *d;
    int *pi;

    printf("Enter number of vertices : ");
    scanf("%d", &G.noOfVertices);

    G.adjmat = (int **)malloc(G.noOfVertices * sizeof(int *));
    int i, j;
    for (i = 0; i < G.noOfVertices; i++)
    {
        G.adjmat[i] = (int *)calloc(G.noOfVertices, sizeof(int));
    }

    color = (int *)calloc(G.noOfVertices, sizeof(int));
    d = (int *)calloc(G.noOfVertices, sizeof(int));
    pi = (int *)calloc(G.noOfVertices, sizeof(int));

    printf("Enter Adjacency Matrix : \n");
    for (i = 0; i < G.noOfVertices; i++)
    {
        for (j = 0; j < G.noOfVertices; j++)
        {
            scanf("%d", &G.adjmat[i][j]);
        }
    }

    printf("Enter the starting node for BFS: ");
    scanf("%d", &start);

    clock_t start1 = clock();
    bfs(&G, start, color, d, pi);
    clock_t end1 = clock();

    printf("Enter the destination node to find shortest path: ");
    scanf("%d", &end);

    printf("Shortest path from %d to %d: ", start, end);
    clock_t start2 = clock();
    printpath(pi, start, end);
    clock_t end2 = clock();
    printf("\n");
    double timetaken = (((double)(end1 - start1)) + ((double)(end2 - start2))) / CLOCKS_PER_SEC;

    return 0;
}