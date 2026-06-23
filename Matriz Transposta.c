#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A[50][50], B[50][50], aux, n;
    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", &n);
    printf("Digite os valores da matriz:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nMatriz originial:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%5d", A[i][j]);
        printf("\n");
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            B[i][j] = A[j][i];
    printf("\nMatriz transposta:\n");
    for(int i = 0; i < n; i++)
        {
        for(int j = 0; j < n; j++)
            printf("%5d", B[i][j]);
        printf("\n");
        }
    printf("\n\n");
    system("pause");
    return 0;

}
