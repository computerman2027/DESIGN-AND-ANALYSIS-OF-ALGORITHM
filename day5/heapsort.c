#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void maxheapify(int* arr, int n,int i)
{
  int l= 2*i+1;
  int r= 2*i+2;
  int largest=i,temp;
  if(l<n && arr[l]>arr[i])
  {
    largest = l;
  }
  if(r<n && arr[r]>arr[largest])
  {
    largest = r;
  }
  if(largest!=i)
  {
    temp= arr[i];
    arr[i]=arr[largest];
    arr[largest]=temp;
    
    maxheapify(arr,n,largest);
  }
}

void buildmaxheap(int* arr, int n)
{
  int i;
  for(i=(n/2)-1;i>=0;i--)
  {
    maxheapify(arr,n,i);
  }
}

void heapsort(int* arr,int n)
{
  buildmaxheap(arr,n);
  int i,temp;
  for(i=n-1;i>0;i--)
  { 
      temp=arr[0];
      arr[0]=arr[i];
      arr[i]=temp;
      n=n-1;
      maxheapify(arr,n,0);
  }
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
    heapsort(arr, n);
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
