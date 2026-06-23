#include <stdio.h>
#include <stdlib.h>
typedef int **matriz;

matriz LerMatriz (int*, int*);
void EscreverMatriz (matriz, int, int);

int main () {
    int m, n; matriz A;
    printf ("Leitura da matriz A\n\n");
      A = LerMatriz (&m, &n);
    printf ("\nMatriz A lida:\n\n");
      EscreverMatriz (A, m, n);
      printf ("\n\n"); system ("pause"); return 0;
}
matriz LerMatriz (int *nlin, int *ncol) {

    matriz MatRetorno; int i, j;
      printf ("Digite as 2 dimensoes: ");
    scanf ("%d%d", nlin, ncol);
    MatRetorno = (int **) malloc (*nlin * sizeof(int*));
    for (i = 0; i < *nlin; i++)
        MatRetorno[i]= (int *) malloc (*ncol * sizeof(int));
    printf ("\nDigite os elementos da matriz\n\n");
    for (i = 0; i < *nlin; i++) {
        printf ("\tLinha %d: ", i);
        for (j = 0; j < *ncol; j++)
            scanf ("%d", &MatRetorno[i][j]);
    }
      return MatRetorno;
}
void EscreverMatriz (matriz Mat, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf ("%5d", Mat[i][j]);
        printf ("\n");
    }
}
