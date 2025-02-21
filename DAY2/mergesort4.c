// merge sort using 2 arrays

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<limits.h>

void merge(int* arr, int p, int q, int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int* left = (int*)malloc((n1+1)*sizeof(int));
    int* right = (int*)malloc((n2+2)*sizeof(int));

    int i,j,k;

    for(i=0;i<n1;i++)
    {
        left[i]=arr[p+i];
    }
    for(j=0;j<n2;j++)
    {
        right[j]=arr[q+j+1];
    }
    left[i]=INT_MAX;
    right[j]=INT_MAX;
    i=0;
    j=0;

    for(k=p;k<=r;k++)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i=i+1;
        }
        else
        {
            arr[k]=right[j];
            j++;
        }
    }
}

void mergesort(int* arr, int p, int r)
{
    if(p<r)
    {
        int q = p+((r-p)/2);
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
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
	mergesort(arr, 0, n - 1);
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
