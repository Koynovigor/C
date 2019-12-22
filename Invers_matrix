#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int **res_matrix(int n, int m);
void rand_matrix(int **matr, int n, int m);
void scan_matrix(int **matr, int n, int m);
void print_matrix(int **matr, int n, int m);
void free_matrix(int **matr, int n);
int det_matr(int **matr, int n, int m);
int **new_matrix (int **matr, int n, int m, int k, int l);
int **matrix_alg_dop(int **matr, int n, int m);
 
 
int main()
{
    int n = 0;
    int m = 0;
    printf("Ввидите размерность матрицы: ");
    scanf("%d %d", &n, &m);
    if ((n <= 0)||(m <= 0))
    {
        printf("Минимальный размер матрицы 1x1");
        return 1;
    }
    if (n != m)
    {
        printf("Обратной матрицы не существуует!");
        return 1;
    }
 
    int **matr = res_matrix(n, m);

    rand_matrix(matr, n, m);

    // scan_matrix(matr, n, m);

    print_matrix(matr, n, m);
    
    // int **new_matr = new_matrix(matr, n, m, n-1, m-1);
    // int det = det_matr(new_matr, n ,m);
    // printf("%d\n", det);

    print_matrix(matrix_alg_dop(matr, n, m), n, m);
 
return (0);
}
 
 
 
 
 
int **res_matrix(int n, int m)
{
    int **matr = calloc(n, sizeof(int*));
    if (matr == NULL)
    {
        perror("Ошибка");
    }
    for (int i = 0; i < n; i++)
    {
        matr[i] = calloc(m, sizeof(int));
    }
return matr;
}
 
void scan_matrix(int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matr[i][j]);
        }
    }
}

void rand_matrix(int **matr, int n, int m)
{  
    srand(time(NULL));
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matr[i][j] =-9 + rand() %19;
        }
    }
}
 
void print_matrix(int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%3d ", matr[i][j]);
        }
    puts("");
    }
}
 
void free_matrix(int **matr, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(matr[i]);
    }
    free (matr);
}

int det_matr(int **matr, int n, int m)
{
    int det = 0;
    if ((n == 1)||(n == 0))
    {
        det = matr[0][0];
        return det;
    }
    if (n >= 3)
    {
        for (int i = 0; i < n; i++)
        {
            int e = 1;
            for (int j = 0; j <  (n+m-i); j ++)
            {
                e = e * (-1);
            }
            det = det + e * matr[n-i-1][m-1] * det_matr((new_matrix(matr, n, m, n-i-1, m-1)), n-1, m-1);
        }
    }
    else
    {
        det = matr[0][0]*matr[1][1] - matr[1][0]*matr[0][1];
    }
    free_matrix(matr, n);

return det;
}

int **new_matrix (int **matr, int n, int m, int k, int l) // k - строчка, l - столбец
{
    int **new_matr = res_matrix(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            new_matr[i][j] = matr[i][j];
        }   
    }
    
    for (int i = 0; i < n; i++)
    {
        if ((i == k)&&(i != n-1))
        {
            for (int j = i; j < n-1; j++)
            {
                new_matr[j] = new_matr[j+1];
            }    
        }
    }

    for (int i = 0; i < m; i++)
    {
        if ((i == l)&&(l != m-1))
        {
            for (int j = i; j < m-1; j++)
            {
                for (int l = 0; l < m; l++)
                {
                    new_matr[l][j] = new_matr[l][j+1];
                }                 
            } 
        }
    } 
return new_matr;
}

int **matrix_alg_dop(int **matr, int n, int m)
{
    int **matr_alg_dop = res_matrix(n, m);
    int **new_matr = new_matrix(matr, n, m, n-1, m-1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int e = 1;
            for (int l = 0; l < i+j; l ++)
            {
                e = e * -1;
            }
            matr_alg_dop[i][j] = e * det_matr(new_matrix(new_matr, n, m, i, j), n-1, m-1);
        }    
    }
return matr_alg_dop;
}
