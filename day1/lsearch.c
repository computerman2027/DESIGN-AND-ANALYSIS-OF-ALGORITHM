#include<stdio.h>
#include<stdlib.h>

void linearsearch(int* arr, int n, int sc)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==sc)
		{
			printf("element found at = %d\n",i);
			return;
		}
	}
	printf("Element not found\n");
}

int main()
{
	int n,i,sc;
	printf("Enter array size : ");
	scanf("%d",&n);
	int* arr=(int*)malloc(n*sizeof(int));
	if(arr==NULL)
	{
		printf("Error in creation\n");
		return 0;
	}
	scanf("Enter elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter number to search : ");
	scanf("%d",&sc);
	linearsearch(arr,n,sc);
	return 0;
}
