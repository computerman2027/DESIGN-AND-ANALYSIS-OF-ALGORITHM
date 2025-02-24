#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int first, int last)
{
    int pivot = arr[first];
    int up = last;
    int down = first;
    while (down < up)
    {
        while (arr[down] <= pivot && down < up)
        {
            down++;
        }
        while (arr[up] > pivot)
        {
            up--;
        }
        if (down < up)
        {
            swap(&arr[down], &arr[up]);
        }
    }
    swap(&arr[first], &arr[up]);
    return up;
}

void quicksort(int arr[], int first, int last)
{
    if (first >= last)
        return;
    int pi = partition(arr, first, last);
    quicksort(arr, first, pi - 1);
    quicksort(arr, pi + 1, last);
}
int main()
{
    int n, i;
    printf("Enter array size : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Error in creation\n");
        return 0;
    }
    printf("Enter data for array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Display before sorting : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    clock_t start = clock();
    quicksort(arr, 0, n - 1);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Display after sorting : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken to run the algorithm: %f seconds\n", time_taken);
    return 0;
}
  
