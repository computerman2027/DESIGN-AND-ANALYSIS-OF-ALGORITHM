#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void printSolution(int *board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int *board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || 
            board[i] - i == col - row || 
            board[i] + i == col + row)
            return false;
    }
    return true;
}

void solveNQueens(int *board, int row, int n, int *solutionCount) 
{
    if (row == n) 
    {
        (*solutionCount)++;
        printf("Solution vector %d: ", *solutionCount);
        for(int i=0;i<n;i++)
        {
          printf("%d ",board[i]);
        }
        printf("\n");
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(board, row + 1, n, solutionCount);
        }
    }
}

int main()
{
  int n;
  
  printf("Enter value of n : ");
  scanf("%d",&n);
  
  int* board=(int*)malloc(n*sizeof(int));
  
  int solCount = 0;
  solveNQueens(board, 0, n, &solCount);

  printf("No of sols : %d\n",solCount);
  return 0;
}
