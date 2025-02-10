#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void selectionsort(int* arr, int n)
{
	int i,j,pos,temp;
	for(i=0;i<n;i++)
	{
		temp=arr[i];
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<temp)		
			{
				temp=arr[j];
				pos=j;
			}
		}
		arr[pos]=arr[i];
		arr[i]=temp;		
	}		
}
int main()
{
	int n,i,term=1,j;
	for(j=1;j<=6;j++)
	{
	term*=10;
	int* arr=(int*)malloc(term*sizeof(int));
	if(arr==NULL)
	{
		printf("Error in creation\n");
		return 0;
	}
	srand(time(NULL));
	for(i=0;i<term;i++)
	{
		arr[i]=rand()%1000;
		//printf("t = %d",arr[i]);
	}
	FILE *fptr=fopen("bubble_sort.txt","a");
	fprintf(fptr,"no of input = %d\n",term);
	clock_t start = clock();
	selectionsort(arr,term);
	clock_t end = clock();
	double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken to run the algorithm for %d: %f seconds\n",term, time_taken);
	fprintf(fptr,"Time taken to run the algorithm: %f seconds\n", time_taken);
	fclose(fptr);
	}
	return 0;
}

