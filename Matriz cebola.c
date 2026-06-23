#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A[50][50]= {0}, m, n,menor, cont = 0;
    printf("Digite as dimensoes da matriz cebola: ");
    scanf("%d %d", &m, &n);
    menor = (m>=n)?n:m;
    if(menor%2==0)
        menor=menor/2;
    else
        menor=menor/2 + 1;
    for(cont = 0; cont <= menor; cont++)

        for(int i = 0 + cont; i < m - cont ; i++)

            for(int j = 0 + cont; j < n - cont; j++)
                A[i][j]++;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}
