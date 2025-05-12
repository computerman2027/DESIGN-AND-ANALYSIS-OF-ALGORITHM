#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printSolution(int *board, int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int *board, int row, int col)
{
    int i;
    for (i = 0; i < row; i++)
    {
        if (board[i] == col ||
            board[i] - i == col - row ||
            board[i] + i == col + row)
            return false;
    }
    return true;
}

void solveNQueens(int *board, int row, int n, int *solutionCount)
{
    int i,col;
    if (row == n)
    {
        (*solutionCount)++;
        printf("Solution vector %d: ", *solutionCount);
        for (i = 0; i < n; i++)
        {
            printf("%d ", board[i]);
        }
        printf("\n");
        printSolution(board, n);
        return;
    }

    for (col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            solveNQueens(board, row + 1, n, solutionCount);
        }
    }
}

int main()
{
    int n;

    printf("Enter value of n : ");
    scanf("%d", &n);

    int *board = (int *)malloc(n * sizeof(int));

    int solCount = 0;
    clock_t s = clock();
    solveNQueens(board, 0, n, &solCount);
    clock_t e = clock();
    double tt = ((double)(e - s)) / CLOCKS_PER_SEC;

    printf("No of sols : %d\n", solCount);
    printf("Time taken : %lf s\n", tt);
    return 0;
}
