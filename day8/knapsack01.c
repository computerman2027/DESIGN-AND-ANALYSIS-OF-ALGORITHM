#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int* knapsack01(int** data, int n, int m)
{
  int** dp=(int**)malloc((n+1)*sizeof(int*));
  
  int i,j,v1,v2;
  
  for(i=0;i<=n;i++)
  {
    dp[i]=(int*)malloc((m+1)*sizeof(int));
  }
  
  for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else
            {
                v1=dp[i-1][j];
                if(j-data[i][0]<0)
                {
                    dp[i][j]=v1;
                }
                else
                {
                    v2=data[i][1]+dp[i-1][j-data[i][0]];
                    dp[i][j]=v1>v2?v1:v2;
                }
            }
        }
    }
    
    printf("displaying dp :\n");

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d\t",dp[i][j]);
        }
        printf("\n");
    }
    
    int* ans =(int*)calloc(n,sizeof(int));

    int starti=n;
    int startj=m;
    
    while(starti>0 && startj>0)
    {
        if(dp[starti][startj]==dp[starti-1][startj])
        {
            starti--;
        }
        else
        {
            ans[starti-1]=1;
            startj-=data[starti][0];
        }
    }
    return ans;
  
}

int main()
{
  int n;

  printf("Enter number of items : ");
  scanf("%d",&n);
  
  int** items=(int**)malloc((n+1)*sizeof(int*));
  int i,capacity;
  for(i=0;i<=n;i++)
  {
     items[i]=(int*)malloc(2*sizeof(int));
  }

  items[0][0]=0;
  items[0][1]=0;
  
 
 for(i=1;i<=n;i++)
 {
     printf("Enter weight of item %d : ",i);
     scanf("%d",&items[i][0]);
     printf("Enter Profit of item %d : ",i);
     scanf("%d",&items[i][1]);
 }
 printf("Enter Capacity of the Bag : ");
 scanf("%d",&capacity);

 clock_t start = clock();
 int* ans = knapsack01(items,n,capacity);
 clock_t end = clock();

 double timetaken = ((double)(end-start))/CLOCKS_PER_SEC;

 printf("Ans vector = ");
 for(i=0;i<n;i++)
 {
     printf("%d ",ans[i]);
 }
 printf("\n");

 printf("CPU time : %lf s\n",timetaken);

 return 0;

 }
 
