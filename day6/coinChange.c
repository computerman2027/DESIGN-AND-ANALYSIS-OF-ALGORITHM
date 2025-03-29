#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct currency
{
    int val;
    int index;
    int noOfUnits;
} Currency;

void sort(Currency *arr, int n)
{
    int i, j;
    Currency temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].val < arr[j + 1].val)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int coinChange(Currency *arr, int n, int target)
{
    sort(arr, n);
    int i;
    for (i = 0; i < n; i++)
    {
        arr[i].noOfUnits = target / arr[i].val;
        target = target % arr[i].val;
    }
    if (target == 0)
        return 0;
    else
        return -1;
}

int main()
{
    int n, i, target;
    printf("Enter no of denomination : ");
    scanf("%d", &n);

    Currency *denominations = (Currency *)malloc(n * sizeof(Currency));

    printf("Enter the Denominations : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &denominations[i].val);
        denominations[i].index = i;
        denominations[i].noOfUnits = 0;
    }

    printf("Enter target : ");
    scanf("%d", &target);

    clock_t start = clock();
    int result = coinChange(denominations, n, target);
    clock_t end = clock();
    
    if (result == -1)
    {
        printf("Not possible to reach target value\n");
    }
    else
    {
        int *ans = (int *)calloc(n, sizeof(int));
        for (i = 0; i < n; i++)
        {
            ans[denominations[i].index] = denominations[i].noOfUnits;
        }
        printf("Ans vector : ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
        printf("Time taken = %lf second\n",((double)(end-start)/CLOCKS_PER_SEC));
    }
    return 0;
}
