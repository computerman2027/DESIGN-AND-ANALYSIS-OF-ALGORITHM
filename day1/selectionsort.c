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
	int n,i;
	printf("Enter array size : ");
	scanf("%d",&n);
	int* arr=(int*)malloc(n*sizeof(int));
	if(arr==NULL)
	{
		printf("Error in creation\n");
		return 0;
	}
	srand(1);
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%1000;
	}
//	printf("Display before sorting : ");
//	for(i=0;i<n;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
	clock_t start = clock();
	selectionsort(arr,n);
	clock_t end = clock();
	double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
//	printf("Display after sorting : ");
//	for(i=0;i<n;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");

	printf("Time taken to run the algorithm: %f seconds\n", time_taken);
	return 0;
}


	