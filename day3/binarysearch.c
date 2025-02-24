#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bisearch(int* arr, int low,int high, int item)
{
  if(low>high)
  {
    return -1;
  }
  else
  {
    int mid = low + ((high-low)/2);
    if(arr[mid]==item)
    {
      return mid;
    }
    if(item>arr[mid])
    {
      return bisearch(arr,mid+1,high,item);
    }
    else
    {
      return bisearch(arr,low,mid-1,item);
    }
  }
}

int main()
{
    int n, i,item;
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
        if(i!=0 && arr[i]<arr[i-1])
        {
          printf("array not in sorted order\n");
          return 0;
        }
    }
    printf("Enter data to be searched in array : ");
    scanf("%d",&item);
    clock_t start = clock();
    int index=bisearch(arr,0,n-1,item);
    clock_t end = clock();
    if(index==-1)
    {
      printf("Item not found\n");
    }
    else
    {
      printf("Item found at %d\n",index);
    }  
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to run the algorithm: %f seconds\n", time_taken);
    return 0;
}
  
    
