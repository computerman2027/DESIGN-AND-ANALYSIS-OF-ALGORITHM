#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int* arr, int p, int q, int R)
{
	int n1=q-p+1;
	int n2=R-q;
	int* l = (int*)malloc(n1*sizeof(int));
	int* r = (int*)malloc(n2*sizeof(int));
	
	int i,j;
	for(i=p;i<=R;i++)
	{
		printf("arr[%d] = %d ",i,arr[i]);
	}
	printf("\n");
	
	for(i=0;i<n1;i++)
	{
	//printf("arr= "
		l[i]=arr[p+i];
	}
	
	for(i=0;i<n1;i++)
	{
		printf("l [%d] = %d ",i,l[i]);
	}
	printf("\n");
	for(j=0;j<n2;j++)
	{
		r[j]=arr[q+1+j];
	}
	
	for(j=0;j<n2;j++)
	{
		printf("r [%d] = %d ",j,r[j]);
	}
	printf("\n");
	
	i=0;
	j=0;
	int k;
	for(k=p;k<=R;k++)
	{
		if(l[i]<=r[j])
		{
		arr[k]=l[i];
		i++;
		}
		else
		{
		arr[k]=r[j];
		j++;
		}
	}
	
	for(i=p;i<=R;i++)
	{
		printf("arr[%d] = %d ",i,arr[i]);
	}
	printf("\n");
}
	

void mergesort(int* arr, int n, int m)
{
	if(n<m)
	{
		int mid=n+((m-n)/2);
		printf("n = %d mid = %d m= %d \n",n,mid,m);
		mergesort(arr,n,mid);
		mergesort(arr,mid+1,m);
		merge(arr,n,mid,m);
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
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Display before sorting : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	clock_t start = clock();
	mergesort(arr,0,n-1);
	clock_t end = clock();
	double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Display after sorting : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	printf("Time taken to run the algorithm: %f seconds\n", time_taken);
	return 0;
}
