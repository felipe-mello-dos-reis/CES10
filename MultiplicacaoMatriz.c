#include <stdio.h>
#include <stdlib.h>

typedef struct matriz matriz;
void LerMatrizQuadrada (matriz*);
void EscreverMatriz (matriz);
matriz MultMat (matriz, matriz);
struct matriz
{
	int ncol, nlin;
	int elem[10][10];
};

int main () {
    int p, i, j, k;
    matriz M, Mpot;
    printf ("POTENCIACAO DE MATRIZ\n\n");

/*    Leitura do expoente     */

    printf ("Digite o expoente: ");
    scanf ("%d", &p);
    while (p < 0) {
        printf ("\tExpoente < 0; Digite novamente: ");
        scanf ("%d", &p);
    }

/*    Leitura e escrita da matriz base    */

    printf ("\nLeitura da matriz base: \n");
    LerMatrizQuadrada (&M);
    printf ("\nMatriz lida: \n\n");
    EscreverMatriz (M);
    printf ("\nExpoente de potenciacao: %d\n", p);
/*    Inicializacao da matriz potencia com a matriz identidade */

    Mpot.nlin = Mpot.ncol = M.nlin;
    for (i = 1; i <= Mpot.nlin; i++) 
        for (j = 1; j <= Mpot.ncol; j++)
            Mpot.elem[i][j] = (i == j) ? 1 : 0;

/* Calculo da matriz potencia        */

    for (k = 1; k <= p; k++)
        Mpot = MultMat (Mpot, M);

/* Escrita da matriz potencia        */

    printf ("\nMatriz potencia: \n\n");
    EscreverMatriz (Mpot);
    printf ("\n\n"); return 0;
}
/*    Funcao LerMatrizQuadrada: ler a matriz argumento pelo teclado    */

void LerMatrizQuadrada (matriz *Mat){
    int i, j, n;
    printf ("\nDigite a dimensao da matriz: ");
    scanf ("%d", &n);
    while (n <= 0) {
        printf ("\tDimensao < 1; Digite novamente: ");
        scanf ("%d", &n);
    }
    (*Mat).ncol = (*Mat).nlin = n;
    for (i = 1; i <= (*Mat).nlin; i++) {
        printf ("\tLinha %d: ", i);
        for (j = 1; j <= (*Mat).ncol; j++)
            scanf ("%d", &(*Mat).elem[i][j]);
    }
}
/*    Funcao EscreverMatriz: escrever a matriz argumento no video    */

void EscreverMatriz (matriz Mat) {
    int i, j;
    for (i = 1; i <= Mat.nlin; i++) {
        for (j = 1; j <= Mat.ncol; j++)
            printf ("%10d", Mat.elem[i][j]);
        printf ("\n");
    }
}
matriz MultMat (matriz M1, matriz M2) {
    int i, j, k, aux; matriz M3;
    M3.nlin = M1.nlin; M3.ncol = M2.ncol;
    if (M1.ncol == M2.nlin) {
        for (i = 1; i <= M3.nlin; i++)
            for (j = 1; j <= M3.ncol; j++) {
                aux = 0;
                for (k = 1; k <= M1.ncol; k++)
                    aux +=                                     M1.elem[i][k]*M2.elem[k][j];
                M3.elem[i][j] = aux;
            }
    }
    else
        for (i = 1; i <= M3.nlin; i++)
            for (j = 1; j <= M3.ncol; j++)
                M3.elem[i][j] = 0;
    return M3;
}
