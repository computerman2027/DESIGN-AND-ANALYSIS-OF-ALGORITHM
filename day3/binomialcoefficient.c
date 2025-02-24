#include <stdio.h>
#include <time.h>

int bcoeff(int n, int k)
{
  if(k==n || k==0)
  {
    return 1;
  }
  return bcoeff(n-1,k-1)+bcoeff(n-1,k);
}

int main()
{
    int n,k, i,item;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter k : ");
    scanf("%d", &k);
    clock_t start = clock();
    int ans=bcoeff(n,k);
    clock_t end = clock();
    printf("%dC%d = %d\n",n,k,ans);
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to run the algorithm: %f seconds\n", time_taken);
    return 0;
}
