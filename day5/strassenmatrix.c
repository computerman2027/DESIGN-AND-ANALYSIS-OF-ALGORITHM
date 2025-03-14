#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct array2D
{
    int **arr;
    int rows;
    int cols;
} Matrix;

Matrix createMatrix(int rows, int cols)
{
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        mat.arr[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}

void printMatrix(Matrix mat, char *matname)
{
    printf("%s\n", matname);
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            printf("%d\t", mat.arr[i][j]);
        }
        printf("\n");
    }
}

Matrix sub(Matrix a, Matrix b)
{
    int n = a.rows;
    Matrix c = createMatrix(n, n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c.arr[i][j] = a.arr[i][j] - b.arr[i][j];
        }
    }
    return c;
}

Matrix add(Matrix a, Matrix b)
{
    int n = a.rows;
    Matrix c = createMatrix(n, n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c.arr[i][j] = a.arr[i][j] + b.arr[i][j];
        }
    }
    return c;
}

void split(Matrix p, Matrix c, int ib, int jb)
{
    int i1, i2, j1, j2;
    for (i1 = 0, i2 = ib; i1 < c.rows; i1++, i2++)
    {
        for (j1 = 0, j2 = jb; j1 < c.rows; j1++, j2++)
        {
            c.arr[i1][j1] = p.arr[i2][j2];
        }
    }
}

void join(Matrix c, Matrix p, int ib, int jb)
{
    int i1, i2, j1, j2;
    for (i1 = 0, i2 = ib; i1 < c.rows; i1++, i2++)
    {
        for (j1 = 0, j2 = jb; j1 < c.rows; j1++, j2++)
        {
            p.arr[i2][j2] = c.arr[i1][j1];
        }
    }
}
Matrix multiplyMatrices(Matrix mat1, Matrix mat2)
{
    int n = mat1.rows;

    Matrix Resultmatrix = createMatrix(n, n);

    if (n == 1)
    {
        Resultmatrix.arr[0][0] = mat1.arr[0][0] * mat2.arr[0][0];
    }
    else
    {
        int m = n / 2;
        Matrix a11 = createMatrix(m, m);
        Matrix a12 = createMatrix(m, m);
        Matrix a21 = createMatrix(m, m);
        Matrix a22 = createMatrix(m, m);
        Matrix b11 = createMatrix(m, m);
        Matrix b12 = createMatrix(m, m);
        Matrix b21 = createMatrix(m, m);
        Matrix b22 = createMatrix(m, m);

        split(mat1, a11, 0, 0);
        split(mat1, a12, 0, m);
        split(mat1, a21, m, 0);
        split(mat1, a22, m, m);
        split(mat2, b11, 0, 0);
        split(mat2, b12, 0, m);
        split(mat2, b21, m, 0);
        split(mat2, b22, m, m);

        Matrix s1 = sub(b12, b22);
        Matrix s2 = add(a11, a12);
        Matrix s3 = add(a21, a22);
        Matrix s4 = sub(b21, b11);
        Matrix s5 = add(a11, a22);
        Matrix s6 = add(b11, b22);
        Matrix s7 = sub(a12, a22);
        Matrix s8 = add(b21, b22);
        Matrix s9 = sub(a11, a21);
        Matrix s10 = add(b11, b12);

        Matrix p1 = multiplyMatrices(a11,s1);
        Matrix p2 = multiplyMatrices(s2,b22);
        Matrix p3 = multiplyMatrices(s3,b11);
        Matrix p4 = multiplyMatrices(a22,s4);
        Matrix p5 = multiplyMatrices(s5,s6);
        Matrix p6 = multiplyMatrices(s7,s8);
        Matrix p7 = multiplyMatrices(s9,s10);
        
        

        Matrix c11 = add(sub(add(p5, p4), p2), p6);
        Matrix c12 = add(p1,p2);
        Matrix c21 = add(p3,p4);
        Matrix c22 = sub(sub(add(p5, p1), p3), p7);

        join(c11, Resultmatrix, 0, 0);
        join(c12, Resultmatrix, 0, n / 2);
        join(c21, Resultmatrix, n / 2, 0);
        join(c22, Resultmatrix, n / 2, n / 2);
    }

    return Resultmatrix;
}

int main()
{
    Matrix mat1, mat2, mat3;
    int i, j, k;
    printf("Enter no of row of 1st matrix : ");
    scanf("%d", &mat1.rows);
    printf("Enter no of column of 1st matrix : ");
    scanf("%d", &mat1.cols);
    printf("Enter no of row of 2nd matrix : ");
    scanf("%d", &mat2.rows);
    printf("Enter no of column of 2nd matrix : ");
    scanf("%d", &mat2.cols);
    if (!(mat1.cols == mat2.rows))
    {
        printf("INVALID MATRIX SIZE. MULTIPLICATION NOT POSSIBLE\n");
        return 0;
    }

    mat3.rows = mat1.rows;
    mat3.cols = mat2.cols;

    mat1 = createMatrix(mat1.rows, mat1.cols);
    mat2 = createMatrix(mat2.rows, mat2.cols);
    mat3 = createMatrix(mat3.rows, mat3.cols);

    printf("Enter elements for 1st matrix\n");
    for (i = 0; i < mat1.rows; i++)
    {
        for (j = 0; j < mat1.cols; j++)
        {
            scanf("%d", &mat1.arr[i][j]);
        }
    }
    printf("Enter elements for 2nd matrix\n");
    for (i = 0; i < mat2.rows; i++)
    {
        for (j = 0; j < mat2.cols; j++)
        {
            scanf("%d", &mat2.arr[i][j]);
        }
    }

    printMatrix(mat1, "Matrix 1");
    printMatrix(mat2, "Matrix 2");

    clock_t start = clock();
    mat3 = multiplyMatrices(mat1, mat2);
    clock_t end = clock();

    printMatrix(mat3, "Matrix 3");

    double timeRequired = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("CPU TIME = %lf seconds\n", timeRequired);

    return 0;
}
