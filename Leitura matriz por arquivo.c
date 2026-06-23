#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A[25][25], m, n, i, j;
    char aux[255];
    FILE *filein;
    filein = fopen("Matriz.txt", "r");
    printf("Informacoes dcontidas no arquivo:");
    printf("\n\n\tMatriz de entrada no arquivo Matriz");
    fscanf(filein, "%d%d", &m, &n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            fscanf(filein, "%d", &A[i][j]);

    fclose(filein);
    printf("\n\nMatriz A:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%4d", A[i][j]);
        printf("\n\n");
    }
    printf("\n\n");
    system("pause");
    return 0;

}
