#include <stdio.h>
#include <time.h>

int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n, i, ans;
    printf("Enter number of fibonacci : ");
    scanf("%d", &n);
    printf("Fibonacci numbers are : ");
    clock_t start = clock();
    for (i = 0; i < n; i++)
    {
        ans = fibo(i);
        printf(i == n - 1 ? "%d\n" : "%d ", ans);
    }
    clock_t end = clock();
    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("CPU time = %lf seconds", timetaken);
    return 0;
}