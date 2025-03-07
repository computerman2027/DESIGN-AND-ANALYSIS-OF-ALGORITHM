#include<stdio.h>
#include<time.h>

int fibo(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

int main()
{
    int n;
    printf("Enter the occurance of fibonacci : ");
    scanf("%d",&n);
    clock_t start=clock();
    int ans = fibo(n);
    clock_t end=clock();
    double timetaken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("%dth fibonacci = %d\n",n,ans);
    printf("CPU time = %lf seconds",timetaken);
    return 0;
}