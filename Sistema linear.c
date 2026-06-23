#include<stdio.h>
#include<stdlib.h>

int main ()
{
    float A[50][50]= {0}, B[50], C[50][50]= {0}, D[50], det=1;
    int n;
    printf("Digite a dimensao da matriz trangular: ");
    scanf("%d", &n);
    printf("Digite os valores da matriz triangular:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0+i; j < n; j++)
        {
            scanf("%f", &A[i][j]);
            C[i][j]=A[i][j];
        }
    printf("\nDigite o vetor B de dimensao %d:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%f", &B[i]);
    printf("\nSolucao do sitema:\n");
    for(int i = 0; i < n; i++)
    {
        D[i]=((-1)^(i))*B[i]/A[i][i];
        printf("\tX%d = %6.3f\n", i, D[i]);
    }
    system("pause");
    return 0;


}
