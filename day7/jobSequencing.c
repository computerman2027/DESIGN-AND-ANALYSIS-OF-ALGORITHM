#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int **arr, int n)
{
    int i, j;
    int *temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j][1] < arr[j + 1][1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int jobscheduling(int **arr, int n, int max)
{
    sort(arr, n);
    int *jobschedule = (int *)calloc(max, sizeof(int));
    int *jobindex = (int *)calloc(max, sizeof(int));
    int i, j, curdateline, maxprofit = 0;
    for (i = 0; i < n; i++)
    {
        curdateline = arr[i][2];
        while (curdateline >= 1)
        {
            if (jobschedule[curdateline - 1] == 0)
            {
                jobindex[curdateline-1]=i;
                jobschedule[curdateline - 1] = arr[i][0];
                maxprofit += arr[i][1];
                break;
            }
            curdateline--;
        }
    }

    printf("Job Sequence (Profit, Deadline) : ");
    for(i=0;i<max;i++)
    {
        if(jobschedule[i]!=0)
        printf("(%d, %d)",arr[jobindex[i]][1],arr[jobindex[i]][2]);
        else 
        printf("(0, 0)");
    }
    printf("\n");
    return maxprofit;
}

int main()
{
    int n, i;
    printf("enter no of jobs : ");
    scanf("%d", &n);

    int **jobs;
    jobs = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        jobs[i] = (int *)malloc(3 * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        jobs[i][0] = i + 1;
        printf("Enter profit : ");
        scanf("%d", &jobs[i][1]);
        printf("Enter deadline : ");
        scanf("%d", &jobs[i][2]);
    }

    int max = jobs[0][2];
    for (i = 0; i < n; i++)
    {
        if (jobs[i][2] > max)
            max = jobs[i][2];
    }

    clock_t start = clock();
    int maxprofit = jobscheduling(jobs, n, max);
    clock_t end = clock();

    printf("MAx profit = %d\n", maxprofit);
    printf("Time taken = %lf second\n", ((double)(end - start) / CLOCKS_PER_SEC));
    return 0;
}