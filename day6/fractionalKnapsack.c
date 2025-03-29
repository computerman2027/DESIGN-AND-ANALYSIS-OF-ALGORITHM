#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// void sort(float** arr, int n)
// {
//   int i,j;
//   float* temp;
//   for(i=0;i<n-1;i++)
//   {
//     for(j=0;j<n-1-i;j++)
//     {
//       if(arr[j][2]<arr[j+1][2])
//       {
//         temp=arr[j];
//         arr[j]=arr[j+1];
//         arr[j+1]=temp;
//       }
//     }
//   }
// }

void sort(float **arr, int n)
{
  int i, j;
  float *temp;
  for (i = 1; i < n; i++)
  {
    temp = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j][2] < temp[2])
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = temp;
  }
}

float *fknap(float **arr, int n, int maxw)
{
  int i;
  for (i = 0; i < n; i++)
  {
    arr[i][2] = arr[i][1] / arr[i][0];
  }
  sort(arr, n);

  for (i = 0; i < n; i++)
  {
    if (arr[i][0] <= maxw)
    {
      arr[i][3] = 1;
      maxw -= arr[i][0];
    }
    else
    {
      arr[i][3] = maxw / arr[i][0];
      maxw = 0;
    }
    if (maxw == 0)
      break;
  }

  float *ans = (float *)calloc(n, sizeof(float));
  for (i = 0; i < n; i++)
  {
    ans[(int)arr[i][4] - 1] = arr[i][3];
  }
  return ans;
}
int main()
{
  int n;
  printf("Enter no of weights : ");
  scanf("%d", &n);

  float **w = (float **)malloc(n * sizeof(float *));
  if (w == NULL)
  {
    printf("Error creating array :");
    return 0;
  }
  else
  {
    int i, maxwt;
    for (i = 0; i < n; i++)
    {
      w[i] = (float *)calloc(5, sizeof(float));
    }

    for (i = 0; i < n; i++)
    {
      printf("Enter Weight : ");
      scanf("%f", &w[i][0]);
      printf("Enter Profit : ");
      scanf("%f", &w[i][1]);
      w[i][4] = i + 1;
    }

    printf("Enter Max weight in knapsack : ");
    scanf("%d", &maxwt);

    clock_t start = clock();
    float *ans = fknap(w, n, maxwt);
    clock_t end = clock();

    printf("Ans vector = ");
    for (i = 0; i < n; i++)
    {
      printf("%f ", ans[i]);
    }
    printf("\n");
    printf("Time taken = %lf second\n", ((double)(end - start) / CLOCKS_PER_SEC));
  }
  return 0;
}
