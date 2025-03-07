#include<stdio.h>
#include<time.h>

void toh(int n,int begin, int dest, int via)
{
    if(n==1)
    {
        printf("move ring 1 from %d to %d via %d\n",begin,dest,via);
        return;
    }
    toh(n-1,begin,via,dest);
    printf("move ring %d from %d to %d via %d\n",n,begin,dest,via);
    toh(n-1,via,dest,begin);
}

int main()
{
    int n;
    printf("Enter number of rings: ");
    scanf("%d", &n);
    clock_t start = clock();
    toh(n,1,3,2);
    clock_t end = clock();
    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("CPU time = %lf seconds", timetaken);
    return 0;
}