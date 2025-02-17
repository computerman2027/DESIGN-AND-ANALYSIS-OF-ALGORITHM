#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int* arr, int n, int mid, int m)
{
	int len=m-n+1;
	int* b=(int*)malloc(len*sizeof(int));
	int i = n,j=mid+1;
	int k=0;
	for(;i<=mid && j<=m;)
	{
		if(arr[i]>arr[j])
		{
			b[k]=arr[j];
			j++;
			k++;
		}
		else
		{
			b[k]=arr[i];
			i++;
			k++;
		}
	}
	if(i<=mid)
	{
		while(i<=mid)
		{
			b[k]=arr[i];
			i++;
			k++;
		}
	}
	else
	{
		b[k]=arr[j];
		j++;
		k++;
	}
	
	for(k=0;k<len;k++)
	{
		arr[n+k]=b[k];
	}
}

void mergesort(int* arr, int n, int m)
{
	if(n<m)
	{
		int mid=n+((m-n)/2);
		mergesort(arr,n,mid);
		mergesort(arr,mid+1,m);
		merge(arr,n,mid,m);
	}
	
}
 
 
int main()
{
	FILE *fptr = fopen("merge_sort.txt", "w");
	fprintf(fptr, "%-12s  %-12s\n", "No of data", "Time taken (s)");
	int n, i, term = 1, j;
	srand(time(NULL));
	for (j = 1; j <= 6; j++)
	{
		term *= 10;
		int *arr = (int *)malloc(term * sizeof(int));
		if (arr == NULL)
		{
			printf("Error in creation\n");
			return 0;
		}
		for (i = 0; i < term; i++)
		{
			 arr[i]=rand()%1000;
			//arr[i] = rand();
			 //printf("t = %d\n", arr[i]);
		}

		// fprintf(fptr,"no of input = %d\n",term);
		clock_t start = clock();
		mergesort(arr,0, term-1);
		clock_t end = clock();
		double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
		
		//printf("ans = \n");
		//for (i = 0; i < term; i++)
		//{
		//	// arr[i]=rand()%1000;
			
		//	 printf("t = %d\n", arr[i]);
		//}
		printf("Time taken to run the algorithm for %d: %f seconds\n", term, time_taken);
		// fprintf(fptr,"Time taken to run the algorithm: %f seconds\n", time_taken);
		fprintf(fptr, "%-12d  %-12.6f\n", term, time_taken);
	}
	fclose(fptr);
	return 0;
}
