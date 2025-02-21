#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *arr, int n, int mid, int m)
{
	int len = m - n + 1;
	int *b = (int *)malloc(len * sizeof(int));
	int i = n, j = mid + 1;
	int k = 0;
	for (; i <= mid && j <= m;)
	{
		if (arr[i] > arr[j])
		{
			b[k] = arr[j];
			j++;
			k++;
		}
		else
		{
			b[k] = arr[i];
			i++;
			k++;
		}
	}
	if (i > mid)
	{
		while (j <= m)
		{
			b[k] = arr[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			b[k] = arr[i];
			i++;
			k++;
		}
	}

	for (k = 0; k < len; k++)
	{
		arr[n + k] = b[k];
	}
}

void mergesort(int *arr, int n, int m)
{
	if (n < m)
	{
		int mid = n + ((m - n) / 2);
		mergesort(arr, n, mid);
		mergesort(arr, mid + 1, m);
		merge(arr, n, mid, m);
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
