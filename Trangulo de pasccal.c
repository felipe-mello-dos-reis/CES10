#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, A[50][50];
    printf("Digite ate qual linha do trangulo de Pascal que deseja exibir: ");
    scanf("%d", &n);
    for(int i = 0; i <= n; i++)
    {
        A[i][i] = 1;
        A[i][0] = 1;
        for(int j = 1; j < i; j++)
        A[i][j] = A[i-1][j-1] + A[i-1][j];
    }
    for(int i = 0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}
