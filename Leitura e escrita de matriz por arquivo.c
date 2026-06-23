#include<stdio.h>
#include<stdlib.h>

int main()
{
    //Declaracao de variaveis
    int A[25][25], B[25][25], positivo[25]= {0}, m, n, i, j, k, x, y, aux, menor[25],impar[25] = {0};
    float medquad[25]= {0};
    char c;

    //Abertura dos arquivos do disco
    FILE *filein, *fileout;
    filein = fopen("input.txt", "r");
    fileout = fopen("output.txt", "w");

    //Identificacao dos resultados
    printf("MANIPULACAO DE MATRIZES BIDIMENSIONAIS\n   REALIZADAS POR ARQUIVOS EM DISCO\n\n");
    printf("Informacoes sobre a matriz:\n\n");
    printf("\tMatriz de entrada no arquivo input.txt\n\n");
    printf("\tMatriz de saida no arquivo output.txt\n");
    fscanf(filein, "%d %d", &m, &n);
    aux = 7*n + 8;

    //Leitura da matriz, e analises das informacoes
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
        {
            fscanf(filein, "%d", &A[i][j]);
            medquad[i]+=A[i][j]*A[i][j];
            if(A[i][j] % 2 != 0)
                impar[i]++;
            if(A[i][j]>0)
                positivo[j]++;
        }

    //Determinacao do menor
    for(j=0; j<n; j++)
        for(i=0; i<m-1; i++)
        {
            if(i==0)
                menor[j] = A[i][j];
            else
                menor[j] = (A[i][j]<menor[j])?A[i][j]:menor[j];
        }

    //Matriz B
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
        {
            B[i][j] = A[i][j];
            x=i+1;
            y=j+1;
            while(0<=x && x<m && 0<=y && y<n)
            {
                B[i][j] += A[x][y];
                x++;
                y++;
            }
            x=i+1;
            y=j-1;
            while(0<=x && x<m && 0<=y && y<n)
            {
                B[i][j] += A[x][y];
                x++;
                y--;
            }
            x=i-1;
            y=j+1;
            while(0<=x && x<m && 0<=y && y<n)
            {
                B[i][j] += A[x][y];
                x--;
                y++;
            }
            x=i-1;
            y=j-1;
            while(0<=x && x<m && 0<=y && y<n)
            {
                B[i][j] += A[x][y];
                x--;
                y--;
            }
        }


    //Impressao da parte superior da tabela
    fprintf(fileout, "Matriz A:\n\n");
    fprintf(fileout, "%*s", aux, " Elementos");
    fprintf(fileout, " |%12s", "MedQuad");
    fprintf(fileout, " |%8s\n", "Impares");
    for(i=0; i<aux+ 1; fprintf(fileout, "-"),i++);
    fprintf(fileout, "|-------------");
    fprintf(fileout, "|--------");

    //Impressao do conteudo da tabela
    for(i=0; i<m; i++)
    {
        fprintf(fileout, "\nLinha %d:", i);
        for(j=0; j<n; j++)
            fprintf(fileout, "%7d", A[i][j]);
        fprintf(fileout, " |%12.2f", medquad[i]/n);
        fprintf(fileout, " |%8d", impar[i]);
    }
    fprintf(fileout, "\n");

    //Impressao da margem inferior da tabela
    for(i=0; i<(aux+ 1); fprintf(fileout, "-"),i++);
    fprintf(fileout, "|-------------");
    fprintf(fileout, "|--------\n");

    //Impressao de estatisticas da matriz
    fprintf(fileout, "> zero :");
    for(j=0; j<n; j++)
        fprintf(fileout, "%7d", positivo[j]);
    fprintf(fileout, "\nMenor  :");
    for(j=0; j<n; j++)
        fprintf(fileout, "%7d", menor[j]);

    //Impressao da Matriz B
    fprintf(fileout, "\n\n\nMatriz B:\n\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            fprintf(fileout, "%7d%", B[i][j]);
        fprintf(fileout, "\n");
    }

    //Encerramento
    fclose(filein);
    fclose(fileout);
    printf("\n\n");
    do
    {
        printf("Deseja encerrar o programa? (s/n)\n");
        c = getch();
    }
    while(c != 's' && c != 'S');
    return 0;

}
