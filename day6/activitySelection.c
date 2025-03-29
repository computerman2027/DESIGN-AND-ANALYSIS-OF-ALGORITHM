#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// void sort(int **arr, int n)
// {
//     int i, j;
//     int *temp;
//     for (i = 0; i < n - 1; i++)
//     {
//         for (j = 0; j < n - i - 1; j++)
//         {
//             if ((arr[j][2] > arr[j + 1][2]) || (arr[j][2] == arr[j + 1][2] && arr[j][1] > arr[j + 1][1]))
//             {
//                 temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

void sort(int **arr, int n)
{
  int i, j;
  int *temp;
  for (i = 1; i < n; i++)
  {
    temp = arr[i];
    j = i - 1;

    while (j >= 0 && (arr[j][2] > temp[2] || (arr[j][2] == temp[2] && arr[j][1] > temp[1])))
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = temp;
  }
}

int *avtselec(int **arr, int n)
{
  sort(arr, n);
  int i = 0, m, k = 1;
  arr[0][3] = k;
  k++;
  for (m = 1; m < n; m++)
  {
    if (arr[i][2] < arr[m][1])
    {
      i = m;
      arr[i][3] = k;
      k++;
    }
  }

  int *ans = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
  {
    ans[arr[i][0]] = arr[i][3];
  }
  return ans;
}
int main()
{
  int n;
  printf("Enter number of activity ");
  scanf("%d", &n);

  int **avt = (int **)malloc(n * sizeof(int *));

  if (avt == NULL)
  {
    printf("array creation failed \n ");
    return 0;
  }
  else
  {
    int i;
    for (i = 0; i < n; i++)
    {
      avt[i] = (int *)malloc(4 * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
      avt[i][0] = i;
      printf("Enter start time : ");
      scanf("%d", &avt[i][1]);

      printf("Enter end time : ");
      scanf("%d", &avt[i][2]);

      avt[i][3] = 0;
    }

    clock_t start = clock();
    int *ans = avtselec(avt, n);
    clock_t end = clock();

    printf("Ans vector = ");
    for (i = 0; i < n; i++)
    {
      printf("%d ", ans[i]);
    }
    printf("\n");
    printf("Time taken = %lf second\n", ((double)(end - start) / CLOCKS_PER_SEC));
  }
  return 0;
}
