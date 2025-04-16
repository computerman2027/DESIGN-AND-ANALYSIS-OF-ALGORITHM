#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **dp;
int size = -1;

int binomialcoeficient(int n, int k)
{
    int i, j;
    if (size == -1)
    {
        dp = (int **)malloc((n + 1) * sizeof(int *));
        for (i = 0; i <= n; i++)
        {
            dp[i] = (int *)malloc((k + 1) * sizeof(int));
            for (j = 0; j <= k; j++)
            {
                dp[i][j] = -1;
            }
        }
        size = n + 1;
    }
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=i;j++)
        {
            // printf("%d %d\n",i,j);
            if(j==0 || j==i)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
    }

    printf("Binomial Solution Table  : \n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%d\t",dp[i][j]);
        }
        printf("\n");
    }
    return dp[n][k];
}

int main()
{
    int n, k,ans;
    clock_t start, end;
    double time_taken;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter k : ");
    scanf("%d", &k);
    if(n<0 || k<0 || k>n)
    {
        printf("INVALID INPUT");
        return 0;
    }
    start = clock();
    ans = binomialcoeficient(n, k);
    end = clock();
    printf("%dC%d = %d\n", n, k, ans);
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to run the algorithm : %f seconds\n", time_taken);
    return 0;
}