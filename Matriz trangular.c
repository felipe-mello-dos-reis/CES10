#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A[50][50] = {0}, n;
    printf("Matriz com o numero 82 nadiagonal e abaixo dela:\nDigite a dimensao da matriz quadrada: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            A[i][j] = 82;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%3d", A[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}


