#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int *arr, int n)
{
	int i, j, flag, temp;
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			return;
	}
}
int main()
{
	FILE *fptr = fopen("bubble_sort.txt", "w");
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
			// arr[i]=rand()%1000;
			arr[i] = rand();
			// printf("t = %d\n", arr[i]);
		}

		// fprintf(fptr,"no of input = %d\n",term);
		clock_t start = clock();
		bubblesort(arr, term);
		clock_t end = clock();
		double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("Time taken to run the algorithm for %d: %f seconds\n", term, time_taken);
		// fprintf(fptr,"Time taken to run the algorithm: %f seconds\n", time_taken);
		fprintf(fptr, "%-12d  %-12.6f\n", term, time_taken);
	}
	fclose(fptr);
	return 0;
}
