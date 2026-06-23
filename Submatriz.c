#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A[50][50], B[50][50], lin, col, i, j, k, l;
    float aux;

    printf("Digite as dimensoes da matriz: ");
    scanf("%d %d", &lin, &col);
    printf("Digite os elementos da matriz:\n");
    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++)
            scanf("%d", &A[i][j]);
    printf("\nDigite o intervalo de linhas que deseja analisar: ");
    scanf("%d %d",&i, &j);
    printf("\nDigite o intervalo de colunas que deseja analisar: ");
    scanf("%d %d", &k, &l);
    printf("\nA submatriz eh dada por: \n");
    for(int m = i - 1; m < j; m++)
        {
            for(int n = k - 1; n < l; n++)
                printf("%4d", A[m][n]);
            printf("\n");
        }
    printf("\n\n");
    system("pause");
    return 0;
}
