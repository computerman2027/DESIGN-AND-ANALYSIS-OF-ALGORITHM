#include <stdio.h>
#include <time.h>

unsigned long long fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{
    int n;
    printf("Enter number : ");
    scanf("%d", &n);
    clock_t start = clock();
    unsigned long long ans = fact(n);
    clock_t end = clock();
    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Factorial = %llu\n", ans);
    printf("CPU time = %lf seconds", timetaken);
    return 0;
}