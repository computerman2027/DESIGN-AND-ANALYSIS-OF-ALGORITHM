#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* number;
int n;

int MAX(int a,int b)
{
    return a>b?a:b;
}
int MIN(int a,int b)
{
    return a<b?a:b;
}

int* maxmin(int x, int y)
{
    int* arr = (int*)malloc(2*sizeof(int));
    if(y-x<=1)
    {
        arr[0]=MAX(number[x],number[y]);
        arr[1]=MIN(number[x],number[y]);
        return arr;
    }
    else
    {
        int* arr2=maxmin(x,(x+y)/2);
        int max1=arr2[0];
        int min1=arr2[1];
        int* arr3=maxmin(((x+y)/2)+1,y);
        int max2=arr3[0];
        int min2=arr3[1];
        arr[0]=MAX(max1,max2);
        arr[1]=MIN(min1,min2);
        return arr;
    }
}


int main()
{
int term=1;
    srand(time(NULL));
    int i,j;
    for (j = 1; j <= 6; j++)
	{
		term *= 10;
		number = (int *)malloc(term * sizeof(int));
		if (number == NULL)
		{
			printf("Error in creation\n");
			return 0;
		}
		for (i = 0; i < term; i++)
		{
			 number[i]=rand()%1000;
			//arr[i] = rand();
			 //printf("t = %d\n", arr[i]);
		}

		// fprintf(fptr,"no of input = %d\n",term);
		clock_t start = clock();
		maxmin(0, term-1);
		clock_t end = clock();
		double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

		printf("Time taken to run the algorithm for %d: %f seconds\n", term, time_taken);
	}
	return 0;
}
