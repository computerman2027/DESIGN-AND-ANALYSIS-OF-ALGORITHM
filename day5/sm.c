#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct array2d
{
  int** arr;
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

Matrix mul(Matrix a, Matrix b)
{
    int n = a.rows;
    int i,j;
    Matrix c = createMatrix(n,n);
    if(a.rows==1)
    {
      c.arr[0][0]=a.arr[0][0]*b.arr[0][0];
      return c;
    }
    
    int m=n/2;
    Matrix a11= createMatrix(m,m);
    Matrix a12= createMatrix(m,m);
    Matrix a21= createMatrix(m,m);
    Matrix a22= createMatrix(m,m);
    
    Matrix b11= createMatrix(m,m);
    Matrix b12= createMatrix(m,m);
    Matrix b21= createMatrix(m,m);
    Matrix b22= createMatrix(m,m);
    
    for(i=0;i<m;i++)
    {
      for(j=0;j<m;j++)
      {
        a11.arr[i][j] = a.arr[i][j];
        a12.arr[i][j] = a.arr[i][j+m];
        a21.arr[i][j] = a.arr[i+m][j];
        a22.arr[i][j] = a.arr[i+m][j+m];
        
        b11.arr[i][j] = b.arr[i][j];
        b12.arr[i][j] = b.arr[i][j+m];
        b21.arr[i][j] = b.arr[i+m][j];
        b22.arr[i][j] = b.arr[i+m][j+m];
      }
    }
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
    
    Matrix p1 = mul(a11,s1);
    Matrix p2 = mul(s2,b22);
    Matrix p3 = mul(s3,b11);
    Matrix p4 = mul(a22,s4);
    Matrix p5 = mul(s5,s6);
    Matrix p6 = mul(s7,s8);
    Matrix p7 = mul(s9,s10);
    
    Matrix c11 = add(sub(add(p5, p4), p2), p6);
    Matrix c12 = add(p1,p2);
    Matrix c21 = add(p3,p4);
    Matrix c22 = sub(sub(add(p5, p1), p3), p7);
    
    c = createMatrix(m,m);
    for(i=0;i<m;i++)
    {
      for(j=0;j<m;j++)
      {
        c.arr[i][j] = c11.arr[i][j];
        c.arr[i][j+m] = c12.arr[i][j];
        c.arr[i+m][j] = c21.arr[i][j];
        c.arr[i+m][j+m] = c22.arr[i][j];
      }
    }
    
    return c;
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
    mat3 = mul(mat1, mat2);
    clock_t end = clock();

    printMatrix(mat3, "Matrix 3");

    double timeRequired = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("CPU TIME = %lf seconds\n", timeRequired);

    return 0;
}
