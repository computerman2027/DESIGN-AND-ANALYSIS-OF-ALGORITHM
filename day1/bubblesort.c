#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void bubblesort(int* arr, int n)
{
	int i,j,flag,temp;;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		return;
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
	srand(time());
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%1000;
	}
	FILE *fptr=fopen("bubble_sort.txt","w");
	fprintf(fptr,"Data before sorting : \n");
	for(i=0;i<n;i++)
	{
		fprintf(fptr,"%d ",arr[i]);
	}
	fprintf(fptr,"\n");
	clock_t start = clock();
	bubblesort(arr,n);
	clock_t end = clock();
	double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
	fprintf(fptr,"data after sorting : \n");
	for(i=0;i<n;i++)
	{
		fprintf(fptr,"%d ",arr[i]);
	}
	fprintf(fptr,"\n");
	printf("Time taken to run the algorithm: %f seconds\n", time_taken);
	fprintf(fptr,"Time taken to run the algorithm: %f seconds\n", time_taken);
	fclose(fptr);
	return 0;
}


	
