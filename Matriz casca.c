#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A[50][50] = {0}, n;
    printf("Matriz com o numero 27 na diagonal e nas bordas:\nDigite a dimensao da matriz quadrada: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        A[i][i] = A[0][i] = A[i][0] = A[n-1][i] = A[i][n-1] = 27;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%3d", A[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}

